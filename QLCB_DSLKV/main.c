#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  int maCB;
  char hoDem[30];
  char ten[10];
  char pb[20];
  char chucVu[20];
  double heSoLuong;
} CB;

struct Node
{
  CB data;
  struct Node *next;
};

// khoi tao list
struct Node *last = NULL;
int size = 0;

void red()
{
  printf("\033[1;31m");
}
void reset()
{
  printf("\033[0m");
}

// init Node
struct Node *initNode(CB data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// add Node
void addNode(CB data)
{
  struct Node *node = initNode(data);
  if (last == NULL)
  {
    last = node;
    last->next = last;
    size++;
    return;
  }
  node->next = last->next;
  last->next = node;
  last = node;
  size++;
}
void printCB(CB cb)
{
  printf("%-10d %-30s %-10s %-20s %-20s %-10.2lf\n", cb.maCB, cb.hoDem, cb.ten, cb.pb, cb.chucVu, cb.heSoLuong);
}
// 12.2. Tìm và in danh sách cán bộ theo Chức vụ
void findCBByChucVu(struct Node *last, char *chucVu)
{
  struct Node *p = last->next;
  int count = 0;
  do
  {
    if (strcmp(strlwr(p->data.chucVu), strlwr(chucVu)) == 0)
    {
      printCB(p->data);
      count++;
    }
    p = p->next;
  } while (p != last->next);
  if (count == 0)
  {
    red();
    printf("Khong tim thay can bo co chuc vu %s\n", chucVu);
    reset();
  }
}

void findCBByLuongAndPB(struct Node *last, double luong, char *pb)
{
  struct Node *p = last->next;
  int count = 0;
  do
  {
    if (p->data.heSoLuong >= luong && strcmp(strlwr(p->data.pb), strlwr(pb)) == 0)
    {
      printCB(p->data);
      count++;
    }
    p = p->next;
  } while (p != last->next);
  if (count == 0)
  {
    red();
    printf("Khong tim thay can bo co he so luong >= %lf va phong ban %s\n", luong, pb);
    reset();
  }
}
// 12.4. Sắp xếp danh sách cán bộ theo thứ tự của tên.
void sortCBByName(struct Node *last)
{
  struct Node *p = last->next;
  struct Node *q = last->next;
  do
  {
    do
    {
      if (strcmp(strlwr(p->data.ten), strlwr(q->data.ten)) < 0)
      {
        CB temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
      q = q->next;
    } while (q != last->next);
    p = p->next;
  } while (p != last->next);
}
void printList(struct Node *last)
{
  struct Node *p = last->next;
  do
  {
    printCB(p->data);
    p = p->next;
  } while (p != last->next);
}
int main()
{
  int checkInput = 0;
  int n;
  while (1)
  {
    printf("1. Nhap danh sach can bo\n");
    printf("2. In danh sach can bo\n");
    printf("3. Tim kiem can bo theo chuc vu\n");
    printf("4. Tim kiem can bo theo he so luong va phong ban\n");
    printf("5. Sap xep danh sach can bo theo ten\n");
    printf("6. Thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", &n);
    CB cb;
    switch (n)
    {
      case 1:
        do
        {
          printf("Nhap ma can bo: ");
          scanf("%d", &cb.maCB);
          if (cb.maCB < 0)
          {
            break;
          }
          printf("Nhap ho dem: ");
          scanf("%s", cb.hoDem);
          printf("Nhap ten: ");
          scanf("%s", cb.ten);
          printf("Nhap phong ban: ");
          scanf("%s", cb.pb);
          printf("Nhap chuc vu: ");
          scanf("%s", cb.chucVu);
          printf("Nhap he so luong: ");
          scanf("%lf", &cb.heSoLuong);
          addNode(cb);
          checkInput = 1;
        } while (cb.maCB >= 0);
        printf("Da nhap xong danh sach can bo\n");
        break;
      case 2:
        if (checkInput == 1)
        {
          printf("\n Danh sach can bo: \n");
          printList(last);
        }
        else
        {
          printf("Chua nhap danh sach can bo\n");
        }
        break;
      case 3:
        if (checkInput == 1)
        {
          char chucVu[20];
          printf("Nhap chuc vu can tim: ");
          scanf("%s", chucVu);
          findCBByChucVu(last, chucVu);
        }
        else
        {
          printf("Chua nhap danh sach can bo\n");
        }
        break;
      case 4:
        if (checkInput == 1)
        {
          double luong;
          char pb[20];
          printf("Nhap he so luong can tim: ");
          scanf("%lf", &luong);
          printf("Nhap phong ban can tim: ");
          scanf("%s", pb);
          findCBByLuongAndPB(last, luong, pb);
        }
        else
        {
          printf("Chua nhap danh sach can bo\n");
        }
        break;
      case 5:
        sortCBByName(last);
        break;
      case 6:
        return 0;
      default:
        printf("Nhap sai, vui long nhap lai\n");
        break;
    }
  }
}
