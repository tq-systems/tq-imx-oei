// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright 2023 NXP
 * Copyright (c) 2025 TQ-Systems GmbH <oss@tq-group.com>, D-82229 Seefeld, Germany.
 */

#include "pin_mux.h"
#include "board.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
#if (BOARD_DEBUG_UART_INSTANCE == 2U)
    /* Configure LPUART 2 */
    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_RXD__LPUART2_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_RXD__LPUART2_RX, IOMUXC_PAD_PD(1U));

    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_TXD__LPUART2_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_TXD__LPUART2_TX, IOMUXC_PAD_DSE(0xFU));
#else
    /* BOARD_DEBUG_UART_INSTANCE configuration is not supported for this board */
#error
#endif
}
