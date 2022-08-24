/*  Created on : Aug 22, 2022
*		file   : card.c
 *      Author : Mohamed Salah Abdelfatah
 *      Email  : mehmetzalah@gmail.com
 *      Phone  : +201069539356
 */

#include "card.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define IS_NOT_ALPHANUMIRIC 0
#define IS_NOT_ALPHAPET 0

#define ACCOUNT_NUMBER_MIN 16
#define ACCOUNT_NUMBER_MAX 19

#define CARD_HOLDER_NAME_MIN 20
#define CARD_HOLDER_NAME_MAX 24

#define CARD_EXPIRY_DATE_LEN 5

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	/* Ask for the cardholder's name */
	printf("Card Holder Name: ");
	scanf("%[^\n]s",cardData->cardHolderName);
	getchar();

	char cardHolderNameLength = strlen(cardData->cardHolderName);

	/* Check characters string */
	int i = 0;
	for(;i<cardHolderNameLength;i++)
		if (isalpha(cardData->cardHolderName[i]) == IS_NOT_ALPHAPET && cardData->cardHolderName[i] != ' ')
			return WRONG_NAME;

	/* Card holder name is 24 characters string max and 20 min */
	if (cardHolderNameLength < CARD_HOLDER_NAME_MIN || cardHolderNameLength > CARD_HOLDER_NAME_MAX)
		return WRONG_NAME;

	return DATA_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	/* ask for the card expiry date */
	printf("Card Expiry Date: ");
	scanf("%[^\n]s", cardData->cardExpirationDate);
	getchar();

	char cardExpiryDateLength = strlen(cardData->cardExpirationDate);

	/* Card expiry date is 5 characters */
	if (cardExpiryDateLength != CARD_EXPIRY_DATE_LEN)
		return WRONG_EXP_DATE;

	/* check format, "MM/YY" '/' should exit */
	if(cardData->cardExpirationDate[2] != '/')
		return WRONG_EXP_DATE;

	/* check format, Number Should in between 0-9 */
	if ((cardData->cardExpirationDate[0] - '0') >= 0 && (cardData->cardExpirationDate[0] - '0') <= 9)
	if ((cardData->cardExpirationDate[1] - '0') >= 0 && (cardData->cardExpirationDate[1] - '0') <= 9)
	if ((cardData->cardExpirationDate[3] - '0') >= 0 && (cardData->cardExpirationDate[3] - '0') <= 9)
	if ((cardData->cardExpirationDate[4] - '0') >= 0 && (cardData->cardExpirationDate[4] - '0') <= 9)
	{
		char month = (cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0');
		
		/* Month should be in between 1 - 12 */
		if(month < 1 || month > 12)
			return WRONG_EXP_DATE;

		return DATA_OK;
	}

	return WRONG_EXP_DATE;

}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{

	/* ask for the card's Primary Account Number */
	printf("Card Primary Account Number: ");
	int value = scanf("%[^\n]s", cardData->primaryAccountNumber);
	getchar();

	char accountNumberLength = strlen(cardData->primaryAccountNumber);

	/* PAN is 20 characters */
	if (accountNumberLength < ACCOUNT_NUMBER_MIN || accountNumberLength > ACCOUNT_NUMBER_MAX)
		return WRONG_PAN;

	char element = 0;

	do
	{
		/* alphanumeric only */
		if(isalnum(cardData->primaryAccountNumber[element]) == IS_NOT_ALPHANUMIRIC)
			return WRONG_PAN;

		element++;

	} while (element < accountNumberLength);

	return DATA_OK;
}
