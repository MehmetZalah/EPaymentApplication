#pragma once
typedef enum
{
	FUNC_getCardHolderName,
	FUNC_getCardExpiryDate,
	FUNC_getCardPAN,
	FUNC_getTransactionDate,
	FUNC_isCardExpired,
	FUNC_getTransactionAmount,
	FUNC_isBelowMaxAmount,
	FUNC_setMaxAmount,
	FUNC_isValidCardPAN,
	FUNC_recieveTransactionData,
	FUNC_isValidAccount,
	FUNC_isAmountAvailable,
	FUNC_saveTransaction,
	FUNC_getTransaction,
	FUNC_isBlockedAccount,


}tFUNC_x;

void TEST_CARD_MODULE(tFUNC_x funcName);
void TEST_TERMINAL_MODULE(tFUNC_x funcName);
