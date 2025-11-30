/*
 * adxl345.h
 *
 *  Created on: Nov 30, 2025
 *      Author: Mehmet Demirbaş
 */

#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_

#include "main.h"

#define DEVID           		0x00 // Cihaz kimlik numarasını (Device ID) tutar
#define THRESH_TAP      		0x1D // Dokunma (tap) algılaması için eşik değeri
#define OFSX            		0x1E // X ekseni için kalibrasyon ofset ayarı
#define OFSY            		0x1F // Y ekseni için kalibrasyon ofset ayarı
#define OFSZ            		0x20 // Z ekseni için kalibrasyon ofset ayarı
#define DUR             		0x21 // Dokunma olayının geçerli sayılması için gereken süre
#define LATENT          		0x22 // Dokunma algılandıktan sonraki bekleme (gecikme) süresi
#define WINDOW          		0x23 // İkinci dokunmanın algılanabileceği zaman penceresi
#define THRESH_ACT      		0x24 // Hareket (aktivite) algılaması için eşik değeri
#define THRESH_INACT    		0x25 // Hareketsizlik (inaktivite) algılaması için eşik değeri
#define TIME_INACT      		0x26 // Hareketsizlik kararı verilmesi için geçmesi gereken süre
#define ACT_INACT_CTL   		0x27 // Aktivite/inaktivite algılaması için eksenleri etkinleştirme ayarı
#define THRESH_FF       		0x28 // Serbest düşüş algılaması için eşik değeri
#define TIME_FF         		0x29 // Serbest düşüş tespiti için gereken minimum süre
#define TAP_AXES        		0x2A // Tek veya çift dokunma algılaması için eksen kontrolü
#define ACT_TAP_STATUS  		0x2B // Dokunma veya aktivitenin kaynağını (hangi eksen olduğunu) gösterir
#define BW_RATE         		0x2C // Veri çıkış hızı ve güç modu kontrolü
#define POWER_CTL       		0x2D // Güç tasarrufu özellikleri ve ölçüm modu kontrolü
#define INT_ENABLE      		0x2E // Kesme (interrupt) fonksiyonlarını etkinleştirme kontrolü
#define INT_MAP         		0x2F // Kesmeleri belirli pinlere yönlendirme ayarı
#define INT_SOURCE      		0x30 // Kesmenin kaynağını (neyin tetiklediğini) gösteren kayıt
#define DATA_FORMAT     		0x31 // Veri formatı ve ölçüm aralığı (G-range) kontrolü
#define DATAX0          		0x32 // X ekseni (LSB) baytı
#define DATAX1          		0x33 // X ekseni (MSB) baytı
#define DATAY0          		0x34 // Y ekseni (LSB) baytı
#define DATAY1          		0x35 // Y ekseni (MSB) baytı
#define DATAZ0          		0x36 // Z ekseni (LSB) baytı
#define DATAZ1          		0x37 // Z ekseni (MSB) baytı
#define FIFO_CTL        		0x38 // FIFO (bellek kuyruğu) kontrol ayarları
#define FIFO_STATUS     		0x39 // FIFO durumunu ve kuyruktaki veri sayısını gösterir

#define TIMEOUT					1000


#define ADXL345_DEVICE_ADDR		0xA6


uint8_t ADXL345_ScanDeviceAddr(void);


#endif /* INC_ADXL345_H_ */

