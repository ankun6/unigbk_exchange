//
// Created by AnKun on 2019/12/16.
//

#ifndef UNIGBK_EXCHANGE_UTIL_H
#define UNIGBK_EXCHANGE_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define swap16(x) ((x&0XFF)<<8|(x&0XFF00)>>8)		//�ߵ��ֽڽ����궨��

// ʮ��������ת�ַ�������0xA->'A'
uint8_t hex2chr(uint8_t hex);

// �ַ�תʮ��������������'A'->0xA
uint8_t chr2hex(uint8_t chr);

// unicode��תgbk�ַ���
void unicode2gbk(void*  gbk, const uint16_t* unicode, uint32_t num);

// gbk�ַ���תunicode��
void gbk2unicode(uint16_t*  unicode, const void* gbk);

// unicodeʮ�������ַ���תgbk�ַ���
void unistr2gbkstr(void* dst, const void* src);

// gbk�ַ���תunicodeʮ�������ַ���
void gbkstr2unistr(void* dst, const void* src);

// Сд��ĸת��д
char lower2upper(char c);

// ��д��ĸתСд
char upper2lower(char c);

// ʮ��������ת�ַ���������0x12BC->"12BC"
void hex2str(void* dst, int hex, bool isUpper);

// ʮ������ת�ַ���������132->"132"
void int2str(void* dst, int num);

// ������ת�������ַ���������0xA->"1010"
void bin2str(void* dst, int bin);

// ������ת�˽����ַ���������0x8->"11"
void oct2str(void* dst, int oct);

#endif //UNIGBK_EXCHANGE_UTIL_H
