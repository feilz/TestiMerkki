#include <avr/io.h>
#include <vilkutus.h>
#include <util/delay.h>


void musta(uint16_t kerrat, uint8_t nopeus){
	uint8_t i;
	for (i=0;i<=31;i++){
		kirkkaus[i]=0;
	}

}
void himmennys(uint16_t kerrat, uint8_t nopeus) //(kerrat = montako kertaa käydään koko kuvio läpi, nopeus = montako kertaa kutsutaan vilkutusta ennenkuin vaihdetaan sävyä)
   {
   uint8_t i;
   int8_t v; //värit
   uint16_t k; // kerrat
   for (k = 0; k < kerrat; k++)
      {
      for (v = 0; v <=15; v++)
         {
         for (i = 0; i <= 31; i++)
            {
            kirkkaus[i] = v;
            }
         for (i = 0; i <= nopeus; i++)
            {
            vilkutus();
            }
         }

      for (v = 14; v >= 0; v--)
         {
         for (i = 0; i <= 31; i++)
            {
            kirkkaus[i] = v;
            }
         for (i = 0; i <= nopeus; i++)
            {
            vilkutus();
            }
         }
      }
   }
void kirkkaustesti()
   {
   int i;
   for (i = 0 ; i<=15; i++)
      {
      kirkkaus[i] = i;
      }
   vilkutus();
   return;
   }
void kaikki()
   {
      int i;
      for (i = 0; i<=31; i++)
         {
         kirkkaus[i] = 1;
         }
      vilkutus();
   }
void isoT(uint16_t kerrat, uint8_t nopeus){
	int8_t order[10] = {3,7,8,9,10,11,15,14,13,12};
	int8_t order2[10] = {3,4,5,6,10,11,31,30,29,28};
	int8_t order3[10] = {3,2,1,0,10,11,31,30,29,28};
	int8_t order4[10]= {19,23,24,25,26,27,15,14,13,12};
	int8_t order5[10]= {19,18,17,16,26,27,15,14,13,12};
	int8_t order6[10]= {19,20,21,22,26,27,15,14,13,12};
	int8_t calc[10] = {15,15,15,15,15,15,10,10,10,10};
	uint8_t i;
	int8_t v; //värit
	uint16_t k; // kerrat
	uint8_t j;
	for (k=0;k<kerrat;k++){
		for (i=0;i<32;i++){
			kirkkaus[i]=0;
		}
		for (v=0;v<10;v++){
			kirkkaus[order[v]]=calc[v];
			kirkkaus[order2[v]]=calc[v];
			kirkkaus[order3[v]]=calc[v];
			kirkkaus[order4[v]]=calc[v];
			kirkkaus[order5[v]]=calc[v];
			kirkkaus[order6[v]]=calc[v];
			for (i=0;i<nopeus;i++){	
				vilkutus();
				_delay_ms(10);
			}
		}
		//for (j=0;j<2;j++){
			for (v = 14; v >= 1; v--){
				for (i = 0; i <= 31; i++){
					kirkkaus[i] = v;
					}
				for (i = 0; i <= nopeus/4; i++){
					vilkutus();
            }
         }
		 for (v = 1; v <=15; v++){
			for (i = 0; i <= 31; i++){
				kirkkaus[i] = v;
				}
			for (i = 0; i <= nopeus/4; i++){
				vilkutus();
				}
			}
		//}
	}	
}
void ympari(uint16_t ctr, uint8_t nopeus)
   {
   ctr = ctr*32;
   uint8_t k = 0; // kohta missä mennään
   volatile uint8_t j = 0; // missä mennään yhdessä framessa
   uint8_t t = 0; //countteri kunnes pysäytettööööäää
   int8_t i = 0;
   uint8_t g = 0; //

//itse kuvio looppi
   while (t < ctr)
      {
      g = nopeus;
      while (g > 0) 
         {
         g--;
         k = 0;
         for (i=0;i<16;i++)
            {
            if (k+j > 31)
               kirkkaus[k+j-32] = i;
            else
               kirkkaus[k+j] = i;
            k++;
            }
         for (i=15; i>1; i -= 3)
            {
            if (k+j < 15){
               kirkkaus[k+j] = i;
			   kirkkaus[16+k+j]=i;
			   }
            else if (k+j<32){
               kirkkaus[k+j] = i;
			   kirkkaus[k+j-16]=i;
			   }
			else {
			kirkkaus[k+j-32]=i;
			kirkkaus[k+j-16]=i;
			}
            k++;
            }
         vilkutus();
         
         }
      j++;
      if (j>31)
         j = 0;
      t++;
      }
   }