#include <stdio.h>
#include "util.h"
#include <string.h>

/*

 ����unicode��gbkת����http://www.mytju.com/classCode/tools/encode_gb2312.asp

 */

void test_gbkstr2unistr(void)
{
	const uint8_t* gbk  = "��A��";				// GBK�ַ���
	uint8_t uni[10];
	unigbk_str_exchange(uni, gbk, 0);
	printf("------ gbk string convert to unicode string: %s\r\n", uni);
}

void test_unistr2gbkstr(void)
{
	const uint8_t* uni = "621100414F60";		// unicodeʮ�������ַ���
	uint8_t gbk[10];
	unigbk_str_exchange(gbk, uni, 1);
	printf("------ unicode string convert to gbk string: %s\r\n", gbk);
}

void test_gbk2unicode(void)
{
	int i = 0;
	uint16_t gbk[4] = {0xCED2, 0xB0AE, 0xC4E3, 0x41};		// �Ұ���A��GBK��
	uint16_t uni[4];
	gbk2unicode(uni, gbk);
	printf("------ gbk convert unicode: \r\n");
	for(i = 0; i != 4; i++)
	printf("       gbk:0x%04X    unicode:0x%04X\r\n", gbk[i], uni[i]);
}

void test__uni2gbk(void)
{
	int i = 0;
	uint16_t uni[4] = {0x6211, 0x7231, 0x4F60, 0x0041};	// �Ұ���A��unicode��
	uint16_t gbk[4];
	unicode2gbk(gbk, uni, 4);
	printf("------ unicode convert gbk: \r\n");
	for(i = 0; i != 4; i++)
		printf("       unicode:0x%04X    gbk:0x%04X\r\n", uni[i], gbk[i]);
}

int main()
{
	test_gbkstr2unistr();		// ����gbk�ַ���תunicode�ַ���
	test_unistr2gbkstr();		// ����unicode�ַ���תgbk�ַ���
	test_gbk2unicode();			// ����gbk��תunicode��
	test__uni2gbk();			// ����unicode��תgbk��
	return 0;
}