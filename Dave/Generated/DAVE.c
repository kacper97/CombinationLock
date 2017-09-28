
/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2014-06-16:
 *     - Initial version<br>
 * 2015-08-28:
 *     - Added CLOCK_XMC1_Init conditionally
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "DAVE.h"

/***********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*******************************************************************************
 * @brief This function initializes the APPs Init Functions.
 *
 * @param[in]  None
 *
 * @return  DAVE_STATUS_t <BR>
 ******************************************************************************/
DAVE_STATUS_t DAVE_Init(void)
{
  DAVE_STATUS_t init_status;
  
  init_status = DAVE_STATUS_SUCCESS;
     /** @Initialization of APPs Init Functions */
     init_status = (DAVE_STATUS_t)CLOCK_XMC1_Init(&CLOCK_XMC1_0);

  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance LockedLed */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&LockedLed); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance ErrorLed */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&ErrorLed); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance push1 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&push1); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance DebounceTimer */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&DebounceTimer); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance DebounceInterupt */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&DebounceInterupt); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance push2 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&push2); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance push4 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&push4); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance push3 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&push3); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance pushReset */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&pushReset); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance InputTimer */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&InputTimer); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance ErrorTimer */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&ErrorTimer); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance RestTimer */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&RestTimer); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance InputInterupt */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&InputInterupt); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance ErrorInterupt */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&ErrorInterupt); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance RestInterupt */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&RestInterupt); 
   }  
  return init_status;
} /**  End of function DAVE_Init */

