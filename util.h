//
// Created by AnKun on 2019/12/16.
//

#ifndef UNIGBK_EXCHANGE_UTIL_H
#define UNIGBK_EXCHANGE_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define swap16(x) ((x&0XFF)<<8|(x&0XFF00)>>8)		//高低字节交换宏定义

uint8_t hex2chr(uint8_t hex);
uint8_t chr2hex(uint8_t chr);
void unicode2gbk(uint16_t*  gbk, const uint16_t* unicode, uint32_t num);
void gbk2unicode(uint16_t*  unicode, const void* gbk);
void unistr2gbkstr(void* dst, const void* src);
void gbkstr2unistr(void* dst, const void* src);
char lower2upper(char c);
char upper2lower(char c);
void hex2str(const void* dst, int hex, bool isUpper);
void int2str(const void* dst, int num);
void bin2str(const void* dst, int bin);
void oct2str(const void* dst, int oct);

#endif //UNIGBK_EXCHANGE_UTIL_H
