//
// Created by AnKun on 2019/12/16.
//

#ifndef UNIGBK_EXCHANGE_UTIL_H
#define UNIGBK_EXCHANGE_UTIL_H

#include <stdint.h>

#define swap16(x) ((x&0XFF)<<8|(x&0XFF00)>>8)		//高低字节交换宏定义

uint8_t hex2chr(uint8_t hex);
uint8_t chr2hex(uint8_t chr);
void uint2hexstr(const void* dst, unsigned int val);
uint16_t ff_wtoupper (uint16_t chr);
uint16_t ff_convert (uint16_t src, uint32_t	dir);
void unicode2gbk(uint16_t*  gbk, const uint16_t* unicode, uint32_t num);
void gbk2unicode(uint16_t*  unicode, const void* gbk);
void unigbk_str_exchange(void* dst, const void* src, int mode);

#endif //UNIGBK_EXCHANGE_UTIL_H
