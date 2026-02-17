## SPDX-License-Identifier: BSD-3-Clause
##
## Copyright (c) 2024-2026 TQ-Systems GmbH <oss@tq-group.com>, D-82229 Seefeld, Germany.
##

cpu     := m33
SOC     := MIMX95
SOCFULL := $(SOC)
SOC_DEVICE_DIR := devices/$(SOC)
RAM_SIZE ?= 2

ifneq ($(REV),A0)
FLAGS += -DCONFIG_DUMMY_TRAIN_DATA_SUPPORT -DCONFIG_ELE
endif

BOARDS_DIR = $(ROOT_DIR)/boards
BOARD_DIR = $(BOARDS_DIR)/$(SOM)

INCLUDE +=  \
	-I$(BOARDS_DIR)  \
	-I$(BOARD_DIR)

OBJS += \
	$(OUT)/board.o

ifeq ($(DEBUG),1)
OBJS += \
	$(OUT)/pin_mux.o
endif

VPATH +=  \
	$(BOARDS_DIR)  \
	$(BOARD_DIR)
