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

// 十六进制数转字符，例：0xA->'A'
uint8_t hex2chr(uint8_t hex);

// 字符转十六进制数，例：'A'->0xA
uint8_t chr2hex(uint8_t chr);

// unicode码转gbk字符串
void unicode2gbk(void*  gbk, const uint16_t* unicode, uint32_t num);

// gbk字符串转unicode码
void gbk2unicode(uint16_t*  unicode, const void* gbk);

// unicode十六进制字符串转gbk字符串
void unistr2gbkstr(void* dst, const void* src);

// gbk字符串转unicode十六进制字符串
void gbkstr2unistr(void* dst, const void* src);

// 小写字母转大写
char lower2upper(char c);

// 大写字母转小写
char upper2lower(char c);

// 十六进制数转字符串，例：0x12BC->"12BC"
void hex2str(void* dst, int hex, bool isUpper);

// 十进制数转字符串，例：132->"132"
void int2str(void* dst, int num);

// 整型数转二进制字符串，例：0xA->"1010"
void bin2str(void* dst, int bin);

// 整型数转八进制字符串，例：0x8->"11"
void oct2str(void* dst, int oct);

#endif //UNIGBK_EXCHANGE_UTIL_H
