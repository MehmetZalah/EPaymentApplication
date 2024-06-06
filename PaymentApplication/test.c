#include "test.h"
#include <assert.h>

#include "card.h"
#include "terminal.h"
#include "server.h"

extern ST_accountsDB_t accountsDBFile;
extern ST_transaction transaction;
extern ST_transaction transactionDB[255];

ST_cardData_t cardData;


void TEST_CARD_MODULE(tFUNC_x funcName)
{

	switch (funcName)
	{

	case FUNC_getCardHolderName:

		/************************* Testing getCardHolderName *******************/

		/* Test Cases:
		Mohamed Salah Abdelfatah
		ali salah ahmed ali ali
		Mohamed Salah Abdelfatah Abdelfatah
		Moh@med $alah Abdelfatah
		111111111111111111111111
		Mohamed

		a                      a
		a a a a a a a a a a a a

		*/


		/*
		* Test Case: 1
		* Input Data: Mohamed Salah Abdelfatah
		* Expected Result : CARD_OK
		* Actual Result : CARD_OK
		*/
		if (getCardHolderName(&cardData) == CARD_OK)
		{
			printf("1- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("1- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: ali salah ahmed ali ali
		* Expected Result : CARD_OK
		* Actual Result : CARD_OK
		*/
		if (getCardHolderName(&cardData) == CARD_OK)
		{
			printf("2- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("2- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 3
		* Input Data: Mohamed Salah Abdelfatah Abdelfatah
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("3- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("3- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 4
		* Input Data: Moh@med $alah Abdelfatah
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("4- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("4- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 5
		* Input Data: 111111111111111111111111
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("5- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("5- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 6
		* Input Data: Mohamed
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("6- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("6- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 7
		* Input Data:                         
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("7- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("7- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 8
		* Input Data: a                      a
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("8- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("8- getCardHolderName Test Fail\n");
		}

		/*
		* Test Case: 9
		* Input Data: a a a a a a a a a a a a
		* Expected Result : WRONG_NAME
		* Actual Result : WRONG_NAME
		*/
		if (getCardHolderName(&cardData) == WRONG_NAME)
		{
			printf("9- getCardHolderName Test Pass\n");
		}
		else
		{
			printf("9- getCardHolderName Test Fail\n");
		}
		/************************************************************************/
		break;

	case FUNC_getCardExpiryDate:

		/********************** Testing getCardExpiryDate ***********************/
		
		/* Test Cases:
		11/22
		13/11
		11/222
		11/2
		00/21
		11022
		1/1/2
		    

		*/

		/*
		* Test Case: 1
		* Input Data: 11/22
		* Expected Result : CARD_OK
		* Actual Result : CARD_OK
		*/
		if (getCardExpiryDate(&cardData) == CARD_OK)
		{
			printf("1- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("1- getCardExpiryDate Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 13/11
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("2- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("2- getCardExpiryDate Test Fail\n");
		}

		/*
		* Test Case: 3
		* Input Data: 11/222
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("3- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("3- getCardExpiryDate Test Fail\n");
		}

		/*
		* Test Case: 4
		* Input Data: 11/2
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("4- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("4- getCardExpiryDate Test Fail\n");
		}

		/*
		* Test Case: 5
		* Input Data: 00/21
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("5- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("5- getCardExpiryDate Test Fail\n");
		}

		/*
		* Test Case: 6
		* Input Data: 11022
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("6- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("6- getCardExpiryDate Test Fail\n");
		}
		/*
		* Test Case: 7
		* Input Data: 1/1/2
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("7- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("7- getCardExpiryDate Test Fail\n");
		}
		/*
		* Test Case: 8
		* Input Data:     
		* Expected Result : WRONG_EXP_DATE
		* Actual Result : WRONG_EXP_DATE
		*/
		if (getCardExpiryDate(&cardData) == WRONG_EXP_DATE)
		{
			printf("8- getCardExpiryDate Test Pass\n");
		}
		else
		{
			printf("8- getCardExpiryDate Test Fail\n");
		}
		/************************************************************************/

		break;

	case FUNC_getCardPAN:

		/********************** Testing getCardPAN ***********************/

		/* Test Cases:
		5482748003516812
		1482748003516812
		54827480 3516812
		148274800351
		148274800351681212345
		482748003516812
		               

		*/

		/*
		* Test Case: 1
		* Input Data: 5482748003516812
		* Expected Result : CARD_OK
		* Actual Result : CARD_OK
		*/
		if (getCardPAN(&cardData) == CARD_OK)
		{
			printf("1- getCardPAN Test Pass\n");
		}
		else
		{
			printf("1- getCardPAN Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 1482748003516812
		* Expected Result : CARD_OK
		* Actual Result : CARD_OK
		*/
		if (getCardPAN(&cardData) == CARD_OK)
		{
			printf("2- getCardPAN Test Pass\n");
		}
		else
		{
			printf("2- getCardPAN Test Fail\n");
		}

		//Sample 54827480 3516812
		/*
		* Test Case: 3
		* Input Data: 54827480 3516812
		* Expected Result : WRONG_PAN
		* Actual Result : WRONG_PAN
		*/
		if(getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("3- getCardPAN Test Pass\n");
		}
		else
		{
			printf("3- getCardPAN Test Fail\n");
		}

		/*
		* Test Case: 4
		* Input Data: 148274800351
		* Expected Result : WRONG_PAN
		* Actual Result : WRONG_PAN
		*/
		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("4- getCardPAN Test Pass\n");
		}
		else
		{
			printf("4- getCardPAN Test Fail\n");
		}

		/*
		* Test Case: 5
		* Input Data: 148274800351681212345
		* Expected Result : WRONG_PAN
		* Actual Result : WRONG_PAN
		*/
		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("5- getCardPAN Test Pass\n");
		}
		else
		{
			printf("5- getCardPAN Test Fail\n");
		}

		/*
		* Test Case: 6
		* Input Data: #482748003516812
		* Expected Result : WRONG_PAN
		* Actual Result : WRONG_PAN
		*/
		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("6- getCardPAN Test Pass\n");
		}
		else
		{
			printf("6- getCardPAN Test Fail\n");
		}

		//Sample     
		/*
		* Test Case: 7
		* Input Data:      
		* Expected Result : WRONG_PAN
		* Actual Result : WRONG_PAN
		*/
		if (getCardPAN(&cardData) == WRONG_PAN)
		{
			printf("7- getCardPAN Test Pass\n");
		}
		else
		{
			printf("7- getCardPAN Test Fail\n");
		}

		/************************************************************************/
		break;

	default:
		break;
	}

	/* Reset Values */
	memset(cardData, 0, sizeof(ST_cardData_t));
}

void TEST_TERMINAL_MODULE(tFUNC_x funcName)
{
	ST_cardData_t cardData;
	ST_terminalData_t terminalData;

	switch (funcName)
	{

	case FUNC_getTransactionDate:

		/************************* Testing getTransactionDate ********************/

		/*
		* Test Case: 1
		* Input Data: 18/10/2022
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		if (getTransactionDate(&terminalData) == TERMINAL_OK)
		{
			if (strcmp(terminalData.transactionDate, "18/10/2022") == 0)
			{
				printf("1- getTransactionDate Test Pass\n");
			}
			else
			{
				printf("1- getTransactionDate Test Fail\n");
			}
		}
		else
		{
			printf("1- getTransactionDate Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 10/10/2022
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		if (getTransactionDate(&terminalData) == TERMINAL_OK)
		{
			if (strcmp(terminalData.transactionDate, "10/10/2022") != 0)
			{
				printf("2- getTransactionDate Test Pass\n");
			}
			else
			{
				printf("2- getTransactionDate Test Fail\n");
			}
		}
		else
		{
			printf("2- getTransactionDate Test Fail\n");
		}
		/************************************************************************/
		break;

	case FUNC_isCardExpired:

		/********************** Testing isCardExpired ***********************/		

		/*
		* Test Case: 1
		* Input Data: 11/22
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		memcpy(cardData.cardExpirationDate,"11/22",5);
		getTransactionDate(&terminalData);

		if (isCardExpired(cardData, terminalData) == TERMINAL_OK)
		{
			printf("1- isCardExpired Test Pass\n");
		}
		else
		{
			printf("1- isCardExpired Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 05/22
		* Expected Result : EXPIRED_CARD
		* Actual Result : EXPIRED_CARD
		*/
		memcpy(cardData.cardExpirationDate, "05/22", 5);
		getTransactionDate(&terminalData);
		if (isCardExpired(cardData, terminalData) == EXPIRED_CARD)
		{
			printf("2- isCardExpired Test Pass\n");
		}
		else
		{
			printf("2- isCardExpired Test Fail\n");
		}


		/*
		* Test Case: 3
		* Input Data: 09/21
		* Expected Result : EXPIRED_CARD
		* Actual Result : EXPIRED_CARD
		*/
		memcpy(cardData.cardExpirationDate, "09/21", 5);
		getTransactionDate(&terminalData);
		if (isCardExpired(cardData, terminalData) == EXPIRED_CARD)
		{
			printf("3- isCardExpired Test Pass\n");
		}
		else
		{
			printf("3- isCardExpired Test Fail\n");
		}
		
		/*
		* Test Case: 4
		* Input Data: 01/21
		* Expected Result : EXPIRED_CARD
		* Actual Result : EXPIRED_CARD
		*/
		memcpy(cardData.cardExpirationDate, "01/21", 5);
		getTransactionDate(&terminalData);
		if (isCardExpired(cardData, terminalData) == EXPIRED_CARD)
		{
			printf("4- isCardExpired Test Pass\n");
		}
		else
		{
			printf("4- isCardExpired Test Fail\n");
		}

		/************************************************************************/
		break;

	case FUNC_getTransactionAmount:

		/********************** Testing getTransactionAmount ***********************/

		/* Test Cases:
		1000
		0
		-100

		*/

		/*
		* Test Case: 1
		* Input Data: 1000
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		if (getTransactionAmount(&terminalData) == TERMINAL_OK)
		{
			printf("1- getTransactionAmount Test Pass\n");
		}
		else
		{
			printf("1- getTransactionAmount Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 0
		* Expected Result : INVALID_AMOUNT
		* Actual Result : INVALID_AMOUNT
		*/
		if (getTransactionAmount(&terminalData) == INVALID_AMOUNT)
		{
			printf("2- getTransactionAmount Test Pass\n");
		}
		else
		{
			printf("2- getTransactionAmount Test Fail\n");
		}

		/*
		* Test Case: 3
		* Input Data: -100
		* Expected Result : INVALID_AMOUNT
		* Actual Result : INVALID_AMOUNT
		*/
		if (getTransactionAmount(&terminalData) == INVALID_AMOUNT)
		{
			printf("3- getTransactionAmount Test Pass\n");
		}
		else
		{
			printf("3- getTransactionAmount Test Fail\n");
		}

		/************************************************************************/
		break;

	case FUNC_isBelowMaxAmount:

		/********************** Testing isBelowMaxAmount ***********************/

		/*
		* Test Case: 1
		* Input Data: trans 1000 - max 5000
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		terminalData.transAmount = 1000;
		terminalData.maxTransAmount = 5000;
		if (isBelowMaxAmount(&terminalData) == TERMINAL_OK)
		{
			printf("1- isBelowMaxAmount Test Pass\n");
		}
		else
		{
			printf("1- isBelowMaxAmount Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: trans 5000 - max 5000
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		terminalData.transAmount = 5000;
		terminalData.maxTransAmount = 5000;
		if (isBelowMaxAmount(&terminalData) == TERMINAL_OK)
		{
			printf("2- isBelowMaxAmount Test Pass\n");
		}
		else
		{
			printf("2- isBelowMaxAmount Test Fail\n");
		}

		/*
		* Test Case: 3
		* Input Data: trans 5000 - max 2000
		* Expected Result : EXCEED_MAX_AMOUNT
		* Actual Result : EXCEED_MAX_AMOUNT
		*/
		terminalData.transAmount = 5000;
		terminalData.maxTransAmount = 2000;
		if (isBelowMaxAmount(&terminalData) == EXCEED_MAX_AMOUNT)
		{
			printf("3- isBelowMaxAmount Test Pass\n");
		}
		else
		{
			printf("3- isBelowMaxAmount Test Fail\n");
		}

		/************************************************************************/
		break;

	case FUNC_setMaxAmount:
		/********************** Testing setMaxAmount ***********************/

		/*
		* Test Case: 1
		* Input Data: #define set to 5000
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		if (setMaxAmount(&terminalData) == TERMINAL_OK)
		{
			printf("1- setMaxAmount Test Pass\n");
		}
		else
		{
			printf("1- setMaxAmount Test Fail\n");
		}

		/************************************************************************/
		break;

	case FUNC_isValidCardPAN:
		/********************** Testing isValidCardPAN ***********************/
		
		/*
		* Test Case: 1
		* Input Data: 5482748003516812
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/
		memset(cardData.primaryAccountNumber, 0, 20);
		memcpy(cardData.primaryAccountNumber,"5482748003516812",16);
		if (isValidCardPAN(&cardData) == TERMINAL_OK)
		{
			printf("1- isValidCardPAN Test Pass\n");
		}
		else
		{
			printf("1- isValidCardPAN Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: 1482748003516812
		* Expected Result : INVALID_CARD
		* Actual Result : INVALID_CARD
		*/
		memset(cardData.primaryAccountNumber, 0, 20);
		memcpy(cardData.primaryAccountNumber, "1482748003516812", 16);
		if (isValidCardPAN(&cardData) == INVALID_CARD)
		{
			printf("2- isValidCardPAN Test Pass\n");
		}
		else
		{
			printf("2- isValidCardPAN Test Fail\n");
		}

		/************************************************************************/
	default:
		break;
	}
}

void TEST_SERVER_MODULE(tFUNC_x funcName)
{

	switch (funcName)
	{

	case FUNC_isValidAccount:
		/************************* Testing isValidAccount ********************/

		/*
		* Test Case: 1
		* Input Data: account number with state running
		* Expected Result : SERVER_OK
		* Actual Result : SERVER_OK
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* Set same account number as user input */
		strcpy(transaction.cardHolderData.primaryAccountNumber, "5561566151515115");

		if (isValidAccount(transaction.cardHolderData, &accountsDBFile) == SERVER_OK)
		{
			printf("1- isValidAccount Test Pass\n");
		}
		else
		{
			printf("1- isValidAccount Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: account number with state blocked
		* Expected Result : BLOCKED_ACCOUNT
		* Actual Result : BLOCKED_ACCOUNT
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* Set same account number as user input */
		strcpy(transaction.cardHolderData.primaryAccountNumber, "5482114404618044");

		if (isValidAccount(transaction.cardHolderData, &accountsDBFile) == BLOCKED_ACCOUNT)
		{
			printf("2- isValidAccount Test Pass\n");
		}
		else
		{
			printf("2- isValidAccount Test Fail\n");
		}

		/*
		* Test Case: 3
		* Input Data: account number that not exist in db
		* Expected Result : ACCOUNT_NOT_FOUND
		* Actual Result : ACCOUNT_NOT_FOUND
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* Set different account number as user input */
		strcpy(transaction.cardHolderData.primaryAccountNumber, "0000111100001111");

		if (isValidAccount(transaction.cardHolderData, &accountsDBFile) == ACCOUNT_NOT_FOUND)
		{
			printf("3- isValidAccount Test Pass\n");
		}
		else
		{
			printf("3- isValidAccount Test Fail\n");
		}
		break;
	case FUNC_isAmountAvailable:
		/************************* Testing isAmountAvailable ********************/

		/*
		* Test Case: 1
		* Input Data: trans amount < account available balance
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* Set amount as user input */
		transaction.terminalData.transAmount = 5000;

		/* DB User Balance */
		accountsDBFile.balance = 6000;

		if (isAmountAvailable(&transaction.terminalData) == TERMINAL_OK)
		{
			printf("1- isAmountAvailable Test Pass\n");
		}
		else
		{
			printf("1- isAmountAvailable Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: trans amount > account available balance
		* Expected Result : LOW_BALANCE
		* Actual Result : LOW_BALANCE
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* Set amount as user input */
		transaction.terminalData.transAmount = 6000;

		/* DB User Balance */
		accountsDBFile.balance = 5000;

		if (isAmountAvailable(&transaction.terminalData) == LOW_BALANCE)
		{
			printf("2- isAmountAvailable Test Pass\n");
		}
		else
		{
			printf("2- isAmountAvailable Test Fail\n");
		}
		break;

	case FUNC_saveTransaction:

		/************************* Testing 	saveTransaction ********************/

		/*
		* Test Case: 1
		* Input Data: save normal transaction in db file
		* Expected Result : SERVER_OK
		* Actual Result : SERVER_OK
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* set trans amount */
		transaction.terminalData.transAmount = 2000;

		/* set primary account number as user input */
		strcpy(transaction.cardHolderData.primaryAccountNumber, "5644184484848484");

		if (isValidAccount(transaction.cardHolderData, &accountsDBFile) == SERVER_OK)
		{
			if (saveTransaction(&transaction) == SERVER_OK)
			{
				printf("1- saveTransaction Test Pass\n");
			}
			else
			{
				printf("1- saveTransaction Test Fail\n");
			}
		}
		else
		{
			printf("1- saveTransaction Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: save normal transaction but db file is not found
		* Expected Result : SAVING_FAILED
		* Actual Result : SAVING_FAILED
		*/

		/* Reset Values */
		memset(accountsDBFile, 0, sizeof(ST_accountsDB_t));
		memset(transaction, 0, sizeof(ST_transaction));

		/* set trans amount */
		transaction.terminalData.transAmount = 2000;

		/* set primary account number as user input */
		strcpy(transaction.cardHolderData.primaryAccountNumber, "5644184484848484");

		if (isValidAccount(transaction.cardHolderData, &accountsDBFile) == SERVER_OK)
		{
			if (saveTransaction(&transaction) == SAVING_FAILED)
			{
				printf("2- saveTransaction Test Pass\n");
			}
			else
			{
				printf("2- saveTransaction Test Fail\n");
			}
		}
		else
		{
			printf("2- saveTransaction Test Fail\n");
		}
		break;

	case FUNC_getTransaction:
		/************************* Testing 	getTransaction ********************/

		/*
		* Test Case: 1
		* Input Data: search for a transaction in transaction db
		* Expected Result : TERMINAL_OK
		* Actual Result : TERMINAL_OK
		*/

		/* insert some transactions */
		transactionDB[0].transactionSequenceNumber = 0;
		transactionDB[1].transactionSequenceNumber = 1;
		transactionDB[2].transactionSequenceNumber = 2;

		if (getTransaction(1,&transaction) == TERMINAL_OK)
		{
			printf("1- getTransaction Test Pass\n");
		}
		else
		{
			printf("1- getTransaction Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: search for a transaction not exist in transaction db
		* Expected Result : TRANSACTION_NOT_FOUND
		* Actual Result : TRANSACTION_NOT_FOUND
		*/

		/* insert some transactions */
		transactionDB[0].transactionSequenceNumber = 0;
		transactionDB[1].transactionSequenceNumber = 1;
		transactionDB[2].transactionSequenceNumber = 2;

		if (getTransaction(4, &transaction) == TRANSACTION_NOT_FOUND)
		{
			printf("2- getTransaction Test Pass\n");
		}
		else
		{
			printf("2- getTransaction Test Fail\n");
		}

		break;
	case FUNC_isBlockedAccount:

		/************************* Testing isBlockedAccount ********************/

		/*
		* Test Case: 1
		* Input Data: account state running
		* Expected Result : RUNNING
		* Actual Result : RUNNING
		*/

		accountsDBFile.state = RUNNING;

		if(isBlockedAccount(&accountsDBFile) == RUNNING)
		{
			printf("1- isBlockedAccount Test Pass\n");
		}
		else
		{
			printf("1- isBlockedAccount Test Fail\n");
		}

		/*
		* Test Case: 2
		* Input Data: account state blocked
		* Expected Result : BLOCKED_ACCOUNT
		* Actual Result : BLOCKED_ACCOUNT
		*/

		accountsDBFile.state = BLOCKED;

		if (isBlockedAccount(&accountsDBFile) == BLOCKED_ACCOUNT)
		{
			printf("2- isBlockedAccount Test Pass\n");
		}
		else
		{
			printf("2- isBlockedAccount Test Fail\n");
		}
		break;
	default:
		break;
	}
}