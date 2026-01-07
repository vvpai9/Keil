#############################################################################
#  Copyright @ 2007 by austriamicrosystems AG
#  All rights are reserved.
#
#  Reproduction in whole or in part is prohibited without the written consent
#  of the copyright owner. Austriamicrosystems reserves the right to make
#  changes without notice at any time. The software is provided as is and
#  Austriamicrosystems makes no warranty, expressed, implied or statutory,
#  including but not limited to any implied warranty of merchantability or
#  fitness for any particular purpose, or that the use will not infringe any
#  third party patent, copyright or trademark. Austriamicrosystems should
#  not be liable for any loss or damage arising from its use.
#############################################################################

#############################################################################
#
#        PROJECT: AS353x
#      COPYRIGHT: austriamicrosystems 2007
#      $Revision: 759 $
#         AUTHOR: U. Herrmann
#     SUBSTITUTE: M. Arpa
#    DESCRIPTION: Makefile for generation of version information.
#
#############################################################################


include Makefile.variables.include

SDK_CFG_FILE_COPIED=sdk_config.h

ifndef SDK_CFG_FILE_ORIG
SDK_CFG_FILE_ORIG=sdk_config_tst.h
endif

all: config

#############################################################################
# remove the generated files
#############################################################################
.PHONY: clean
clean: stdclean
	$(RM) sdk_config.h


include Makefile.rules.include

# test -z "$$AVr" && AVr="0"                                            \;
#
#
                

