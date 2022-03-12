/*
	TIMER 2

	DHT PIN PA1
 */
#include "stm32f1xx.h"
#include "DHT11.h"

uint32_t tim;
uint8_t check;



void delay_us(uint32_t times){

	TIM2->CNT = 0;
	while(TIM2->CNT <= (times)){
	}
}


void DHT11_init(){

	RCC->APB1ENR |= (1<<0); /* TIM2 timer clock enable */
	TIM2->ARR =0xFFFF;
	TIM2->PSC = 48-1;
	TIM2->EGR |=(1<<0);//Update generation
	TIM2->CR1 |= (1<<0);//Counter enable
	// start GPIOA
	RCC->APB2ENR |= 1<<2;

}


uint32_t temperature(){
	return (uint32_t)data[2];
}

uint32_t humidity(){
	return (uint32_t)data[0];
}

void DHT11_Read_data(){
		//Set GPIO PA1 OUTPUT
		GPIOA->CRL &= ~(3<<4); /* clear bit 4, 5 */
		GPIOA->CRL |= (1<<4); /* Output mode, max speed 10 MHz */
		GPIOA->CRL &= ~(3<<6); /* clear bit 6, 7 */
		GPIOA->CRL |= (1<<6); /* General purpose output Open-drain */
		//keo PA1 xuong muc thap trong 20ms
		GPIOA->ODR &= ~(1<<1);
		delay_us(19000);
		GPIOA->ODR |=  (1<<1);
		//set PA1 INPUT
		GPIOA->CRL &= ~(3<<4); /* clear bit 4, 5 */
		GPIOA->CRL &= ~(3<<6); /* clear bit 6, 7 */
		GPIOA->CRL |= (2<<6); /* INPUT  PP */

		//*********************************************************************
		// cho chan PA1 len cao
		TIM2->CNT =0;
		while((TIM2->CNT) <10){
				if((GPIOA->IDR & (1<<1)) != 0){
					break;
				}
     }
		tim = TIM2->CNT;
		 if(tim >= 10){
			    goto DHT11_Fail;
				//while(1);
		 }
		 // cho chan PA1 xuong thap
		TIM2->CNT =0;
		while(TIM2->CNT < 45){
				if((GPIOA->IDR & (1<<1)) == 0){
					break;
				}
     }
		 if((TIM2->CNT >= 45) || (TIM2->CNT <= 10)){
			    goto DHT11_Fail;
				//while(1);
		 }
		  // cho chan PA1 len cao lai
		TIM2->CNT = 0;
		while(TIM2->CNT<92){
				if((GPIOA->IDR & (1<<1)) != 0){
					break;
				}
     }
		 if((TIM2->CNT >= 90) || (TIM2->CNT <= 70)){
			 goto DHT11_Fail;
			//while(1);
		 }
		  // cho chan PA1 xuong thap
		 TIM2->CNT=0;
		while(TIM2->CNT<98){
				if((GPIOA->IDR & (1<<1)) == 0){
					break;
				}
     }

		 if((TIM2->CNT >= 95) || (TIM2->CNT <= 75)){
			 goto DHT11_Fail;
			//while(1);
		 }
		 //**************************************************

// nhan byte 0

		 for(int i =0; i<8; i++){

			 		  // cho chan PA1 len cao
			TIM2->CNT=0;
			while(TIM2->CNT<65){
					if((GPIOA->IDR & (1<<1)) != 0){
						break;
					}
			}

			 if((TIM2->CNT >= 65) || (TIM2->CNT <= 45)){
				 goto DHT11_Fail;
				//while(1);
			 }
		  // cho chan PA1 xuong thap
			TIM2->CNT=0;
			while(TIM2->CNT< 85){
					if((GPIOA->IDR & (1<<1)) == 0){
						if((GPIOA->IDR & (1<<1)) == 0){
							break;
							}
						}
			 }
			if((TIM2->CNT >= 85) || (TIM2->CNT <= 10)){
				goto DHT11_Fail;
				//while(1);//******************fail****************************
			 }

			 //nhan du lieu
			 data[0] <<= 1;
			 if(TIM2->CNT >= 50){
					//nhan duoc bit 1
				 data[0] |= 1;
			 }
			 else{
				 data[0] &= ~1;
				 // nhan duoc bit 0
			 }
		}
// nhan byte 1

		 for(int i =0; i<8; i++){

				 		  // cho chan PA1 len cao
				TIM2->CNT=0;
				while(TIM2->CNT<65){
						if((GPIOA->IDR & (1<<1)) != 0){
							break;
						}
				}

				 if((TIM2->CNT >= 65) || (TIM2->CNT <= 45)){
					 goto DHT11_Fail;
					//while(1);
				 }
			  // cho chan PA1 xuong thap
				TIM2->CNT=0;
				while(TIM2->CNT< 85){
						if((GPIOA->IDR & (1<<1)) == 0){
							if((GPIOA->IDR & (1<<1)) == 0){
								break;
								}
							}
				 }
				if((TIM2->CNT >= 85) || (TIM2->CNT <= 10)){
					goto DHT11_Fail;
					//while(1);//******************fail****************************
				 }

				 //nhan du lieu
				 data[1] <<= 1;
				 if(TIM2->CNT >= 50){
						//nhan duoc bit 1
					 data[1] |= 1;
				 }
				 else{
					 data[1] &= ~1;
					 // nhan duoc bit 0
				 }
			}
// nhan byte 2
		 for(int i =0; i<8; i++){

				 		  // cho chan PA1 len cao
				TIM2->CNT=0;
				while(TIM2->CNT<65){
						if((GPIOA->IDR & (1<<1)) != 0){
							break;
						}
				}

				 if((TIM2->CNT >= 65) || (TIM2->CNT <= 45)){
					  goto DHT11_Fail;
					//while(1);
				 }
			  // cho chan PA1 xuong thap
				TIM2->CNT=0;
				while(TIM2->CNT< 85){
						if((GPIOA->IDR & (1<<1)) == 0){
							if((GPIOA->IDR & (1<<1)) == 0){
								break;
								}
							}
				 }
				if((TIM2->CNT >= 85) || (TIM2->CNT <= 10)){
					goto DHT11_Fail;
					//while(1);//******************fail****************************
				 }

				 //nhan du lieu
				 data[2] <<= 1;
				 if(TIM2->CNT >= 50){
						//nhan duoc bit 1
					 data[2] |= 1;
				 }
				 else{
					 data[2] &= ~1;
					 // nhan duoc bit 0
				 }
			}
//nhan byte 3
		 for(int i =0; i<8; i++){

				 		  // cho chan PA1 len cao
				TIM2->CNT=0;
				while(TIM2->CNT<65){
						if((GPIOA->IDR & (1<<1)) != 0){
							break;
						}
				}

				 if((TIM2->CNT >= 65) || (TIM2->CNT <= 45)){
					 goto DHT11_Fail;
					//while(1);
				 }
			  // cho chan PA1 xuong thap
				TIM2->CNT=0;
				while(TIM2->CNT< 85){
						if((GPIOA->IDR & (1<<1)) == 0){
							if((GPIOA->IDR & (1<<1)) == 0){
								break;
								}
							}
				 }
				if((TIM2->CNT >= 85) || (TIM2->CNT <= 10)){
					goto DHT11_Fail;
					//while(1);//******************fail****************************
				 }

				 //nhan du lieu
				 data[3] <<= 1;
				 if(TIM2->CNT >= 50){
						//nhan duoc bit 1
					 data[3] |= 1;
				 }
				 else{
					 data[3] &= ~1;
					 // nhan duoc bit 0
				 }
			}
// nhan byte 4
		 for(int i =0; i<8; i++){

				 // cho chan PA1 len cao
				TIM2->CNT=0;
				while(TIM2->CNT<65){
						if((GPIOA->IDR & (1<<1)) != 0){
							break;
						}
				}

				 if((TIM2->CNT >= 65) || (TIM2->CNT <= 45)){
					 goto DHT11_Fail;
					//while(1);
				 }
			  // cho chan PA1 xuong thap
				TIM2->CNT=0;
				while(TIM2->CNT< 85){
						if((GPIOA->IDR & (1<<1)) == 0){
							if((GPIOA->IDR & (1<<1)) == 0){
								break;
								}
							}
				 }
				if((TIM2->CNT >= 85) || (TIM2->CNT <= 10)){
					goto DHT11_Fail;
					//while(1);//******************fail****************************
				 }

				 //nhan du lieu
				 data[4] <<= 1;
				 if(TIM2->CNT >= 50){
						//nhan duoc bit 1
					 data[4] |= 1;
				 }
				 else{
					 data[4] &= ~1;
					 // nhan duoc bit 0
				 }
			}

	check = data[0]+data[1]+data[2]+data[3];
	 if(check != data[4]){
		 goto DHT11_Fail;
		 //while(1);
	 }
DHT11_Fail:{
	data[0]=0;
	data[2]=0;

}

}

