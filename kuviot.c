#include <avr/io.h>
#include <vilkutus.h>

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

void ympari(uint16_t ctr, uint8_t nopeus)
   {
   ctr = ctr*32;
   uint8_t k = 0; // kohta missä mennään
   volatile uint8_t j = 0; // missä mennään yhdessä framessa
   uint8_t t = 0; //countteri kunnes pysäytettööööäää
   int8_t i = 0;
   uint8_t g = 0; //
//sisäänhäivytys
   /*for (i=0;i<16;i++)
      {
      kirkkaus[k] = i-15;
      k++;
      }
   for (i=15; i>1; i -= 3)
      {
      kirkkaus[k] = i-15;
      k++;
      }
   for (i=0; i<15; i++)
      {
      for (g = 0; g <= nopeus; g++)
         {
         vilkutus();
         }
      for (k=29; k>0; k--) //29 = ledit mihin yllä asetettiin negatiiviset luvut
         {
         kirkkaus[i] = kirkkaus[i]+1;
         }
      }

   k=0;
*/

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
            if (k+j > 31)
               kirkkaus[k+j-32] = i;
            else 
               kirkkaus[k+j] = i;
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

