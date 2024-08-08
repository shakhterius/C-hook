#include <stdio.h>
#include <locale.h>
#include <string.h>
//
#define EntryPointInProgram main // #define EntryPointToProgram main
#define EOS "" // #define EOS '\0'
//
int EntryPointInProgram(int argc, char *argv[])
{
    setlocale(0, ""); // ��������� ������� ����
    //
    FILE *h = NULL;
    h = fopen("compiler.cfg", "rb"); // ������� ����
    if (h == NULL) // ���� ���� �� ����������, ��
    {
        h = fopen("compiler.cfg", "wb"); // �������� ���, �
        if (h == NULL) // ����� ��������, ��� ���� ������
        {
            printf("�� ���� ������� ����.");
            return -1;
        }
        printf("���� ������ � ������ �� ������.\n");
        char cfg[32] = "��������� � �����";
        // �������� ��� ����������������� ������� �� ���������
        fputs(cfg, h);
    }
    else
    {
        printf("���� ������ �� ������.\n"); // ���� ���� ����������, �� ������� � ���� ���������������� ������
        char cfg[32] = EOS; // cfg[0] = EOS;
        printf("A | cfg[] = \"%s\"\n", cfg);
        fgets(cfg, sizeof (cfg), h);
        printf("B | cfg[] = \"%s\"\n", cfg);
        if (!strcmp(cfg, "��������� � �������"))
        {
            printf("��������� � �������.");
            printf("���������� ���������� ���������� ������� main: %d.\n", argc);
            for (int i = 0; i < argc; ++i){
                printf("�������� %d: %s\n", i, argv[i]);
            }
        }
        else if (!strcmp(cfg, "��������� � �����")){
            printf("��������� � �����.\n");
        }
    }
    fclose(h);
    printf("���� ������.");
    return 0;
}
// char fop(FILE *h, const char *fn);
/*
    char symbol;
    if ((symbol = fgetc(h)) == EOF) // ���� ���� ����, ��
    {
        printf("���� ������.\n");
    }
    else printf("���� �������� ������.");
*/
// if (fop(h, "compiler.cfg") == -1) return 1;