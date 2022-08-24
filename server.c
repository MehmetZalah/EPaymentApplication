/*  Created on : Aug 22, 2022
*		file   : server.c
 *      Author : Mohamed Salah Abdelfatah
 *      Email  : mehmetzalah@gmail.com
 *      Phone  : +201069539356
 */

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

ST_accountsDB_t accountsDBFile;
ST_transaction transactionDB[255];

#define IS_FOUND 0

typedef enum
{
	STATE_TRANSACTION_AMOUNT,
	STATE_CHECK_EXCEDDED_AMOUNT,
	STATE_VALID_ACCOUNT,
	STATE_AMOUNT_AVAILABLE,
	STATE_CHECK_ACCOUNT_BLOCKED,
	STATE_SAVE_TRANSACTION,
}tSTATE_y;

tSTATE_y transactionState = STATE_TRANSACTION_AMOUNT;

EN_transStat_t recieveTransactionData(ST_transaction* transData)
{
	switch (transactionState)
	{
	case STATE_TRANSACTION_AMOUNT:
		if (getTransactionAmount(&transData->terminalData) == INVALID_AMOUNT)
		{
			printf("\t\tMSG:: DECLINED_INSUFFECIENT_FUND\n");
			return DECLINED_INSUFFECIENT_FUND;
		}

	case STATE_CHECK_EXCEDDED_AMOUNT:
		if (isBelowMaxAmount(&transData->terminalData) == EXCEED_MAX_AMOUNT)
		{
			printf("\t\tMSG:: DECLINED_INSUFFECIENT_FUND\n");
			return DECLINED_INSUFFECIENT_FUND;
		}

	case STATE_VALID_ACCOUNT:
		if (isValidAccount(transData->cardHolderData, &accountsDBFile) == ACCOUNT_NOT_FOUND)
		{
			printf("\t\tMSG:: FRAUD_CARD\n");
			return FRAUD_CARD;
		}

	case STATE_AMOUNT_AVAILABLE:
		if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
		{
			printf("\t\tMSG:: DECLINED_INSUFFECIENT_FUND\n");
			return DECLINED_INSUFFECIENT_FUND;
		}

	case STATE_CHECK_ACCOUNT_BLOCKED:
		if (isBlockedAccount(&accountsDBFile) == BLOCKED_ACCOUNT)
		{
			printf("\t\tMSG:: DECLINED_STOLEN_CARD\n");
			return DECLINED_STOLEN_CARD;
		}

	case STATE_SAVE_TRANSACTION:
		if (saveTransaction(transData) == SAVING_FAILED)
		{
			printf("\t\tMSG:: INTERNAL_SERVER_ERROR\n");
			return INTERNAL_SERVER_ERROR;
		}
	default:
		printf("\t\tMSG:: APPROVED\n");
		return APPROVED;
	}

}

EN_serverError_t isValidAccount(ST_cardData_t cardData, ST_accountsDB_t* accountRefrence)
{
	char temp[15];
	memset(temp,0,15);

	FILE* databaseFile;
	char line[50];
	char accountState[8];

	databaseFile = fopen("AccountsDB.txt", "r");

	if (databaseFile == NULL)
	{
		fclose(databaseFile);
		return ACCOUNT_NOT_FOUND;
	}

	while (fgets(line, 40, databaseFile))
	{
		int i = 0;
		int y = 0;
		for (; i < 50; i++)
		{
			/* Character Separator & END OF primaryAccountNumber */
			if (line[i] == ',')
			{
				/* checks if the PAN exists or not in the server's database */
				if (strcmp(cardData.primaryAccountNumber, accountRefrence->primaryAccountNumber) == IS_FOUND)
				{
					
					i++;

					/* get the balance for this primaryAccountNumber */
					for (;i<50; i++)
					{
						if (line[i] == ',')
						{
							accountRefrence->balance = atof(temp);

							i++;

							/* get account state */
							for (;i<50;i++)
							{
								if (line[i] == ';')
								{
									if (strcmp(accountState, "RUNNING") == IS_FOUND)
										accountRefrence->state = RUNNING;
									else
										accountRefrence->state = BLOCKED;
								}
								else
								{
									accountState[i] = line[i];
								}
							}

							fclose(databaseFile);
							return TERMINAL_OK;
						}
						else
						{
							temp[y] = line[i];
							y++;
						}
					}
				}
				memset(accountRefrence->primaryAccountNumber, 0, sizeof(accountRefrence->primaryAccountNumber));
				accountRefrence->balance = 0;
				break;
			}
			else
			{
				accountRefrence->primaryAccountNumber[i] = line[i];
			}
		}
	}
	fclose(databaseFile);
	return ACCOUNT_NOT_FOUND;
}

/* if using global array
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	/* checks if the PAN exists or not in the server's database 
int i = 0;
for (; i < sizeof(accountsDB) / sizeof(accountsDB[0]); i++)
	if (strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber) == IS_FOUND)
	{
		accountID = i;
		return OK;
	}

return ACCOUNT_NOT_FOUND;
}
*/

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	/* checks if the transaction's amount is available or not */
	if (termData->transAmount > accountsDBFile.balance)
		return LOW_BALANCE;
	else
		return TERMINAL_OK;
}

EN_serverError_t saveTransaction(ST_transaction* transData)
{
	accountsDBFile.balance -= transData->terminalData.transAmount;
	
	char temp[50];
	memset(temp, 0, 50);

	char temp_filename[255];

	FILE* updatedDatabaseFile;
	FILE* databaseFile;
	char line[50];

	strcpy(temp_filename, "tempAccountsDB.txt");

	databaseFile = fopen("AccountsDB.txt", "r");
	updatedDatabaseFile = fopen(temp_filename, "w");

	if (databaseFile == NULL || updatedDatabaseFile == NULL)
		return SAVING_FAILED;

	int recordNum = 0;

	while (fgets(line, 50, databaseFile))
	{
		int i = 0;
		int y = 0;
		for (; i < 50; i++)
		{
			/* Character Separator & END OF primaryAccountNumber */
			if (line[i] == ',')
			{
				/* checks if the PAN exists or not in the server's database */
				if (strcmp(transData->cardHolderData.primaryAccountNumber, accountsDBFile.primaryAccountNumber) == IS_FOUND)
				{
					/* store updated record*/
					sprintf(temp, "%s,%f,RUNNING;\n", transData->cardHolderData.primaryAccountNumber, accountsDBFile.balance);
					fputs(temp, updatedDatabaseFile);
				}
				else
				{
					/* store record as its*/
					fputs(line, updatedDatabaseFile);
					memset(accountsDBFile.primaryAccountNumber, 0, sizeof(accountsDBFile.primaryAccountNumber));
				}
				break;
			}
			else
			{
				accountsDBFile.primaryAccountNumber[i] = line[i];
			}
		}
		recordNum++;
	}

	fclose(updatedDatabaseFile);
	fclose(databaseFile);

	remove("AccountsDB.txt");
	rename("tempAccountsDB.txt", "AccountsDB.txt");


	memcpy(transactionDB[transData->transactionSequenceNumber].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate, 5);
	memcpy(transactionDB[transData->transactionSequenceNumber].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName, 24);
	memcpy(transactionDB[transData->transactionSequenceNumber].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber, 19);
	memcpy(transactionDB[transData->transactionSequenceNumber].terminalData.transactionDate, transData->terminalData.transactionDate, 10);

	transactionDB[transData->transactionSequenceNumber].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
	transactionDB[transData->transactionSequenceNumber].terminalData.transAmount = transData->terminalData.transAmount;
	transactionDB[transData->transactionSequenceNumber].transactionSequenceNumber = transData->transactionSequenceNumber;
	transactionDB[transData->transactionSequenceNumber].transState = APPROVED;

	if (getTransaction(transData->transactionSequenceNumber, &transactionDB) == TRANSACTION_NOT_FOUND)
		return SAVING_FAILED;

	/* gives a sequence number to a transaction */
	transData->transactionSequenceNumber++;


	return SERVER_OK;
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction* transData)
{
	int i = 0;
	for (; i < sizeof(transactionDB) / sizeof(transactionDB[0]); i++)
		if (transactionSequenceNumber == transactionDB[i].transactionSequenceNumber)
			return TERMINAL_OK;

	return TRANSACTION_NOT_FOUND;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence->state == BLOCKED)
		return BLOCKED_ACCOUNT;
	else
		return SERVER_OK;
}