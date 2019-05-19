#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct byte// разбиение int на биты
{
    unsigned char c1:1;
    unsigned char c2:1;
    unsigned char c3:1;
    unsigned char c4:1;
};
union char_byte//int размером в 4 бита
{
    char b;
    struct byte i;

};
struct mac//MAC-адрес
{
    union char_byte m[12];//Массив 12 цифр в 16-ричной системе счисления

};

void fill(struct mac *address,char* str);//Заполнение MAC-адреса
void swap(struct mac *address);//Переключение самого левого бита
void print(struct mac address);//Вывоб MAC-адреса на экран

int main() {
    struct mac address;
    int size;
    char* str=NULL;
    str=(char*)malloc(100* sizeof(char));
    if(str)
    {
        printf("Hello!\nWrite your MAC-address:");
        //Ввод MAC-адреса
        fgets(str,100,stdin);
        size=strlen(str);
        str[size-1]='\0';
        //"Переводим строку в структуру mac"
        fill(&address,str);
        printf("Your address:");
        print(address);
        //Меняем бит
        swap(&address);
        printf("Changed address:");
        print(address);

        puts("Press Enter to end program");
        getchar();
    }

    return 0;
}
void fill(struct mac* address,char* str)//Заполнение структуры mac
{
    int i=0;

    while(*str!='\0')
    {
        if(*str!=':')
        {
            //получение цифры, в зависимости от считанного символа
            switch(*str)
            {
                case '0':address->m[i].b=0;break;
                case '1':address->m[i].b=1;break;
                case '2':address->m[i].b=2;break;
                case '3':address->m[i].b=3;break;
                case '4':address->m[i].b=4;break;
                case '5':address->m[i].b=5;break;
                case '6':address->m[i].b=6;break;
                case '7':address->m[i].b=7;break;
                case '8':address->m[i].b=8;break;
                case '9':address->m[i].b=9;break;
                case 'a':address->m[i].b=10;break;
                case 'b':address->m[i].b=11;break;
                case 'c':address->m[i].b=12;break;
                case 'd':address->m[i].b=13;break;
                case 'e':address->m[i].b=14;break;
                case 'f':address->m[i].b=15;break;
                default:address->m[i].b=0;//если символ некорректный
            }
            i++;
        }

        str++;
    }
}

void swap(struct mac *address)
{
    address->m[0].b=address->m[0].b^8;//Выполняем xor на первый слева int с 8, тем самым меняя левый бит
}

void print(struct mac address)
{
    int i;
    for(i=0;i<12;i++)
    {
        if(((i%2)==0)&&(i!=0))printf(":");
        printf("%0x",address.m[i].b);//Вывод int в 16-ричном формате
    }
    printf("\n");
}