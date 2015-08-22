#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=CONFIGURATION.c main.c SYSTEM.c EXCEPTIONS.c INTERRUPTS.c USER.c MISC.c DMA.c UART.c ADC.c TIMERS.c PWM.c SUPERCAP.c FLASH.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/CONFIGURATION.o ${OBJECTDIR}/main.o ${OBJECTDIR}/SYSTEM.o ${OBJECTDIR}/EXCEPTIONS.o ${OBJECTDIR}/INTERRUPTS.o ${OBJECTDIR}/USER.o ${OBJECTDIR}/MISC.o ${OBJECTDIR}/DMA.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/TIMERS.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/SUPERCAP.o ${OBJECTDIR}/FLASH.o
POSSIBLE_DEPFILES=${OBJECTDIR}/CONFIGURATION.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/SYSTEM.o.d ${OBJECTDIR}/EXCEPTIONS.o.d ${OBJECTDIR}/INTERRUPTS.o.d ${OBJECTDIR}/USER.o.d ${OBJECTDIR}/MISC.o.d ${OBJECTDIR}/DMA.o.d ${OBJECTDIR}/UART.o.d ${OBJECTDIR}/ADC.o.d ${OBJECTDIR}/TIMERS.o.d ${OBJECTDIR}/PWM.o.d ${OBJECTDIR}/SUPERCAP.o.d ${OBJECTDIR}/FLASH.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/CONFIGURATION.o ${OBJECTDIR}/main.o ${OBJECTDIR}/SYSTEM.o ${OBJECTDIR}/EXCEPTIONS.o ${OBJECTDIR}/INTERRUPTS.o ${OBJECTDIR}/USER.o ${OBJECTDIR}/MISC.o ${OBJECTDIR}/DMA.o ${OBJECTDIR}/UART.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/TIMERS.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/SUPERCAP.o ${OBJECTDIR}/FLASH.o

# Source Files
SOURCEFILES=CONFIGURATION.c main.c SYSTEM.c EXCEPTIONS.c INTERRUPTS.c USER.c MISC.c DMA.c UART.c ADC.c TIMERS.c PWM.c SUPERCAP.c FLASH.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX350F128L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/CONFIGURATION.o: CONFIGURATION.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CONFIGURATION.o.d 
	@${RM} ${OBJECTDIR}/CONFIGURATION.o 
	@${FIXDEPS} "${OBJECTDIR}/CONFIGURATION.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CONFIGURATION.o.d" -o ${OBJECTDIR}/CONFIGURATION.o CONFIGURATION.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/SYSTEM.o: SYSTEM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SYSTEM.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM.o 
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM.o.d" -o ${OBJECTDIR}/SYSTEM.o SYSTEM.c   
	
${OBJECTDIR}/EXCEPTIONS.o: EXCEPTIONS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EXCEPTIONS.o.d 
	@${RM} ${OBJECTDIR}/EXCEPTIONS.o 
	@${FIXDEPS} "${OBJECTDIR}/EXCEPTIONS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EXCEPTIONS.o.d" -o ${OBJECTDIR}/EXCEPTIONS.o EXCEPTIONS.c   
	
${OBJECTDIR}/INTERRUPTS.o: INTERRUPTS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INTERRUPTS.o.d 
	@${RM} ${OBJECTDIR}/INTERRUPTS.o 
	@${FIXDEPS} "${OBJECTDIR}/INTERRUPTS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/INTERRUPTS.o.d" -o ${OBJECTDIR}/INTERRUPTS.o INTERRUPTS.c   
	
${OBJECTDIR}/USER.o: USER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/USER.o.d 
	@${RM} ${OBJECTDIR}/USER.o 
	@${FIXDEPS} "${OBJECTDIR}/USER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/USER.o.d" -o ${OBJECTDIR}/USER.o USER.c   
	
${OBJECTDIR}/MISC.o: MISC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MISC.o.d 
	@${RM} ${OBJECTDIR}/MISC.o 
	@${FIXDEPS} "${OBJECTDIR}/MISC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MISC.o.d" -o ${OBJECTDIR}/MISC.o MISC.c   
	
${OBJECTDIR}/DMA.o: DMA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DMA.o.d 
	@${RM} ${OBJECTDIR}/DMA.o 
	@${FIXDEPS} "${OBJECTDIR}/DMA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DMA.o.d" -o ${OBJECTDIR}/DMA.o DMA.c   
	
${OBJECTDIR}/UART.o: UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c   
	
${OBJECTDIR}/ADC.o: ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	@${FIXDEPS} "${OBJECTDIR}/ADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC.o.d" -o ${OBJECTDIR}/ADC.o ADC.c   
	
${OBJECTDIR}/TIMERS.o: TIMERS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMERS.o.d 
	@${RM} ${OBJECTDIR}/TIMERS.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMERS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TIMERS.o.d" -o ${OBJECTDIR}/TIMERS.o TIMERS.c   
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c   
	
${OBJECTDIR}/SUPERCAP.o: SUPERCAP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERCAP.o.d 
	@${RM} ${OBJECTDIR}/SUPERCAP.o 
	@${FIXDEPS} "${OBJECTDIR}/SUPERCAP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SUPERCAP.o.d" -o ${OBJECTDIR}/SUPERCAP.o SUPERCAP.c   
	
${OBJECTDIR}/FLASH.o: FLASH.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FLASH.o.d 
	@${RM} ${OBJECTDIR}/FLASH.o 
	@${FIXDEPS} "${OBJECTDIR}/FLASH.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FLASH.o.d" -o ${OBJECTDIR}/FLASH.o FLASH.c   
	
else
${OBJECTDIR}/CONFIGURATION.o: CONFIGURATION.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CONFIGURATION.o.d 
	@${RM} ${OBJECTDIR}/CONFIGURATION.o 
	@${FIXDEPS} "${OBJECTDIR}/CONFIGURATION.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CONFIGURATION.o.d" -o ${OBJECTDIR}/CONFIGURATION.o CONFIGURATION.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/SYSTEM.o: SYSTEM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SYSTEM.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM.o 
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM.o.d" -o ${OBJECTDIR}/SYSTEM.o SYSTEM.c   
	
${OBJECTDIR}/EXCEPTIONS.o: EXCEPTIONS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EXCEPTIONS.o.d 
	@${RM} ${OBJECTDIR}/EXCEPTIONS.o 
	@${FIXDEPS} "${OBJECTDIR}/EXCEPTIONS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EXCEPTIONS.o.d" -o ${OBJECTDIR}/EXCEPTIONS.o EXCEPTIONS.c   
	
${OBJECTDIR}/INTERRUPTS.o: INTERRUPTS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INTERRUPTS.o.d 
	@${RM} ${OBJECTDIR}/INTERRUPTS.o 
	@${FIXDEPS} "${OBJECTDIR}/INTERRUPTS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/INTERRUPTS.o.d" -o ${OBJECTDIR}/INTERRUPTS.o INTERRUPTS.c   
	
${OBJECTDIR}/USER.o: USER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/USER.o.d 
	@${RM} ${OBJECTDIR}/USER.o 
	@${FIXDEPS} "${OBJECTDIR}/USER.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/USER.o.d" -o ${OBJECTDIR}/USER.o USER.c   
	
${OBJECTDIR}/MISC.o: MISC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MISC.o.d 
	@${RM} ${OBJECTDIR}/MISC.o 
	@${FIXDEPS} "${OBJECTDIR}/MISC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MISC.o.d" -o ${OBJECTDIR}/MISC.o MISC.c   
	
${OBJECTDIR}/DMA.o: DMA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DMA.o.d 
	@${RM} ${OBJECTDIR}/DMA.o 
	@${FIXDEPS} "${OBJECTDIR}/DMA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DMA.o.d" -o ${OBJECTDIR}/DMA.o DMA.c   
	
${OBJECTDIR}/UART.o: UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c   
	
${OBJECTDIR}/ADC.o: ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	@${FIXDEPS} "${OBJECTDIR}/ADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC.o.d" -o ${OBJECTDIR}/ADC.o ADC.c   
	
${OBJECTDIR}/TIMERS.o: TIMERS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMERS.o.d 
	@${RM} ${OBJECTDIR}/TIMERS.o 
	@${FIXDEPS} "${OBJECTDIR}/TIMERS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TIMERS.o.d" -o ${OBJECTDIR}/TIMERS.o TIMERS.c   
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${RM} ${OBJECTDIR}/PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c   
	
${OBJECTDIR}/SUPERCAP.o: SUPERCAP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SUPERCAP.o.d 
	@${RM} ${OBJECTDIR}/SUPERCAP.o 
	@${FIXDEPS} "${OBJECTDIR}/SUPERCAP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SUPERCAP.o.d" -o ${OBJECTDIR}/SUPERCAP.o SUPERCAP.c   
	
${OBJECTDIR}/FLASH.o: FLASH.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FLASH.o.d 
	@${RM} ${OBJECTDIR}/FLASH.o 
	@${FIXDEPS} "${OBJECTDIR}/FLASH.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FLASH.o.d" -o ${OBJECTDIR}/FLASH.o FLASH.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Catalyst_RPI_daughter.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
