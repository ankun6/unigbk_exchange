#include <stdio.h>
#include "util.h"
#include <string.h>
#include <stdlib.h>
/*

 ����unicode��gbkת����http://www.mytju.com/classCode/tools/encode_gb2312.asp

 */

void test_gbkstr2unistr(void)
{
	const uint8_t* gbk  = (const uint8_t*)"��A��";				// GBK�ַ���
	uint8_t uni[10];
	gbkstr2unistr(uni, gbk);
	printf("------ gbk string convert to unicode string: %s\r\n", uni);
}

void test_unistr2gbkstr(void)
{
	const uint8_t* uni = (const uint8_t*)"621100414F60";		// unicodeʮ�������ַ���
	uint8_t gbk[10];
	unistr2gbkstr(gbk, uni);
	printf("------ unicode string convert to gbk string: %s\r\n", gbk);
}

void test_gbk2uni(void)
{
	int i = 0;
	const uint8_t* gbk = (const uint8_t*)"�Ұ���A";		// GBK�ַ���
	uint16_t uni[4];
	gbk2unicode(uni, gbk);
	printf("------ gbk convert unicode: \r\n");
	for(i = 0; i != 4; i++)
	{
		uint16_t gbkcode = *(((uint16_t *)gbk) + i);
		gbkcode = gbkcode >= 0x81 ? swap16(gbkcode) : gbkcode;
		printf("   gbk:0x%04X    unicode:0x%04X\r\n", gbkcode, uni[i]);
	}
}

void test_uni2gbk(void)
{
	uint16_t uni[4] = {0x6211, 0x7231, 0x4F60, 0x0041};	// �Ұ���A��unicode��
	uint8_t gbk[10];
	unicode2gbk(gbk, uni, 4);
	printf("------ unicode convert gbk: [0x%X 0x%X 0x%X 0x%X] -> %s\r\n", uni[0], uni[1], uni[2], uni[3], gbk);
}

void test_hex2str(void)
{
	uint8_t* hexstr[8];
	hex2str(hexstr, 0xAABB0033, true);
	printf("------ hex convert to string: \"%s\"\r\n", (char *)hexstr);
	hex2str(hexstr, 0x0AB2, true);
	printf("------ hex convert to string: \"%s\"\r\n", (char *)hexstr);
}

int main()
{
	test_gbkstr2unistr();		// ����gbk�ַ���תunicodeʮ�������ַ���
	test_unistr2gbkstr();		// ����unicodeʮ�������ַ���תgbk�ַ���
	test_gbk2uni();				// ����gbk��תunicode��
	test_uni2gbk();				// ����unicode��תgbk��
	test_hex2str();				// ����ʮ������ת�ַ���
	return 0;
}
