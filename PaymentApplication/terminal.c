/*  Created on : Aug 22, 2022
*		file   : terminal.c
 *      Author : Mohamed Salah Abdelfatah
 *      Email  : mehmetzalah@gmail.com
 *      Phone  : +201069539356
 */

#include <stdio.h>
#include <time.h>
#include "terminal.h"

#define MAX_AMOUNT 5000.00

#define MONTH_OFFSET 3
#define YEAR_OFFSET 8

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	/* read the current date from your computer */
	time_t t = time(NULL);
	struct tm* currentDate = localtime(&t);

	/* store date into terminal data in format dd/mm/yyyy */
	sprintf(termData->transactionDate,"%02d/%02d/%d", currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);

	/* check transaction date 10 characters */
	if (strlen(termData->transactionDate) != 10)
		return WRONG_DATE;

	return OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	/* convert transactionDate to integer */
	char currentMonth = atoi(termData.transactionDate+MONTH_OFFSET);
	char currentYear = atoi(termData.transactionDate+YEAR_OFFSET);

	/* get Card Expiry Month and Year */
	char cardExpiryMonth = (cardData.cardExpirationDate[0] - '0') * 10 + (cardData.cardExpirationDate[1] - '0');
	char cardExpiryYear = (cardData.cardExpirationDate[3] - '0') * 10 + (cardData.cardExpirationDate[4] - '0');

	/* compares the card expiry date with the transaction date */
	if (cardExpiryYear > currentYear)
		return DATA_OK;
	
	if(cardExpiryYear == currentYear)
		if(cardExpiryMonth >= currentMonth)
			return DATA_OK;

	return EXPIRED_CARD;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	/* Ask's for the transaction amount */
	printf("Transaction Amount: ");
	scanf("%f", &termData->transAmount);
	getchar();

	/* check if transaction amount is less than or equal to 0 */
	if (termData->transAmount <= 0)
		return INVALID_AMOUNT;

	return OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	/* compares the transaction amount with the terminal max amount */
	if (termData->transAmount > termData->maxTransAmount)
		return EXCEED_MAX_AMOUNT;

	return OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	/* sets the maximum allowed amount into terminal data */
	termData->maxTransAmount = MAX_AMOUNT;

	/* check if transaction max amount less than or equal to 0 */
	if (termData->maxTransAmount <= 0)
		return INVALID_MAX_AMOUNT;

	return OK;
}