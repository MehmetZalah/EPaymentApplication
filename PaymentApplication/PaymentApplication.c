/*  Created on : Aug 22, 2022
 *		file   : PaymentApplication.c
 *      Author : Mohamed Salah Abdelfatah
 *      Email  : mehmetzalah@gmail.com
 *      Phone  : +201069539356
 */

#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "test.h"

#define ENABLE_TEST_CASES 0

int main()
{

#if ENABLE_TEST_CASES == 1
	
	/* TEST CARD MODULE */
	TEST_CARD_MODULE(FUNC_getCardHolderName);
	TEST_CARD_MODULE(FUNC_getCardExpiryDate);
	TEST_CARD_MODULE(FUNC_getCardPAN);

	/* TEST TERMINAL MODULE */
	TEST_TERMINAL_MODULE(FUNC_getTransactionDate);
	TEST_TERMINAL_MODULE(FUNC_isCardExpired);
	TEST_TERMINAL_MODULE(FUNC_getTransactionAmount);
	TEST_TERMINAL_MODULE(FUNC_isBelowMaxAmount);
	TEST_TERMINAL_MODULE(FUNC_setMaxAmount);
	TEST_TERMINAL_MODULE(FUNC_isValidCardPAN);

	/* TEST SERVER MODULE */
	TEST_SERVER_MODULE(FUNC_isValidAccount);
	TEST_SERVER_MODULE(FUNC_isAmountAvailable);
	TEST_SERVER_MODULE(FUNC_saveTransaction);
	TEST_SERVER_MODULE(FUNC_getTransaction);
	TEST_SERVER_MODULE(FUNC_isBlockedAccount);

#else

	while (1)
	{
		appStart();
	}
#endif
}
