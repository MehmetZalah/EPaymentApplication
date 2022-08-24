/*  Created on : Aug 22, 2022
*		file   : app.c
 *      Author : Mohamed Salah Abdelfatah
 *      Email  : mehmetzalah@gmail.com
 *      Phone  : +201069539356
 */

#include "app.h"
#include "terminal.h"
#include "server.h"
#include "card.h"

typedef enum
{
	STATE_CONFIG,
	STATE_CARD_HOLDER_NAME,
	STATE_CARD_EXPIRATION_DATE,
	STATE_CARD_PAN,
	STATE_VALID_CARD_PAN,
	STATE_TRANSACTION_DATE,
	STATE_CHECK_EXPIRATION_DATE,
	STATE_RECEIVE_TRANSACTION_DATA,
	STATE_END
}tSTATE_x;

tSTATE_x state = STATE_CONFIG;

extern ST_transaction transactionDB[255];

ST_transaction transaction;

void appStart(void)
{
	switch (state)
	{
	case STATE_CONFIG:
		if (setMaxAmount(&transaction.terminalData) == INVALID_MAX_AMOUNT)
		{
			printf("\t\tMSG:: INVALID_MAX_AMOUNT\n");
			break;
		}
	case STATE_CARD_HOLDER_NAME:
		if (getCardHolderName(&transaction.cardHolderData) == WRONG_NAME)
		{
			printf("\t\tMSG:: WRONG_NAME\n");
			break;
		}

	case STATE_CARD_EXPIRATION_DATE:
		if (getCardExpiryDate(&transaction.cardHolderData) == WRONG_EXP_DATE)
		{
			printf("\t\tMSG:: WRONG_EXP_DATE\n");
			break;
		}

	case STATE_CARD_PAN:
		if (getCardPAN(&transaction.cardHolderData) == WRONG_PAN)
		{
			printf("\t\tMSG:: WRONG_PAN\n");
			break;
		}

	case STATE_VALID_CARD_PAN:
		if (isValidCardPAN(&transaction.cardHolderData) == INVALID_CARD)
		{
			printf("\t\tMSG:: INVALID_CARD\n");
			break;
		}

	case STATE_TRANSACTION_DATE:
		if (getTransactionDate(&transaction.terminalData) == WRONG_DATE)
		{
			printf("\t\tMSG:: WRONG_DATE\n");
			break;
		}

	case STATE_CHECK_EXPIRATION_DATE:
		if (isCardExpired(transaction.cardHolderData, transaction.terminalData) == EXPIRED_CARD)
		{
			printf("\t\tMSG:: EXPIRED_CARD\n");
			break;
		}

	case STATE_RECEIVE_TRANSACTION_DATA:
		if (recieveTransactionData(&transaction) == INTERNAL_SERVER_ERROR)
		{
			printf("\t\tMSG:: INTERNAL_SERVER_ERROR\n");
			break;
		}

	default:
		break;
	}

}