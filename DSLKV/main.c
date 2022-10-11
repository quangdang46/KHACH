#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int info;
  struct Node *next;
};

//khoi tao list
struct Node *last = NULL;
int size = 0;

//

struct Node *initNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->info = data;
  newNode->next = NULL;
  return newNode;
}

void addHead(int data)
{
  struct Node *temp= (struct Node *)malloc(sizeof(struct Node));
  if (last == NULL)
  {
    temp->info = data;
    temp->next = temp;
    last = temp;
    size++;
    return;
  }
  temp->info = data;
  temp->next = last->next;
  last->next = temp;
  size++;
}

struct Node *getNodeByIndex(int index)
{
  if (index < 0 || index >= size)
  {
    return NULL;
  }
  int i = 0;
  struct Node *temp = last->next;
  while (i < index)
  {
    temp = temp->next;
    i++;
  }
  return temp;
}

void addNodeByIndex(int data, int index)
{
  struct Node *temp = getNodeByIndex(index);
  if (temp == NULL)
  {
    printf("Index out of range");
    return;
  }
  struct Node *newNode = initNode(data);
  struct Node *nextNode = temp->next;
  newNode->next = nextNode;
  temp->next = newNode;
  size++;
}

int isEmpty()
{
  return last == NULL ? 1 : 0;
}

void viewList()
{
  if (last == NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  struct Node *temp= last->next;

  do
  {
    printf("%d ", temp->info);
    temp = temp->next;
  } while (temp != last->next);
  printf("\n");
}

int check(int n)
{
  int i = 1;
  while (i * i < n)
  {
    i++;
  }
  return i * i == n ? 1 : 0;
}

int countScp()
{
  if (isEmpty())
  {
    return 0;
  }
  struct Node *temp = last->next;
  int count = 0;
  do
  {
    count += check(temp->info);
    temp = temp->next;
  } while (temp != last->next);
  return count;
}

double tbc(int x, int y)
{
  if (isEmpty())
  {
    return 0;
  }
  struct Node *temp = last->next;
  double sum = 0;
  int count = 0;
  do
  {
    if (temp->info >= x && temp->info <= y)
    {
      sum += temp->info;
      count++;
    }
    temp = temp->next;
  } while (temp != last->next);
  return count == 0 ? 0 : sum / count;
}

double tbc_le_duong_5()
{
  if (isEmpty())
  {
    return 0;
  }
  int count = 0;
  double sum = 0;
  struct Node *temp = last->next;
  do
  {
    int data = temp->info;
    if (data > 0 && data % 5 == 0 && data % 2 != 0)
    {
      sum += data;
      count++;
    }
  } while (temp != last->next);
  return count == 0 ? 0 : sum / count;
}
void red(){
  printf("\033[1;31m");
}
void reset(){
  printf("\033[0m");
}
int main()
{
  int input = 0;
  int checkInput = 0;
  while (1)
  {
    printf("1. Them vao dau danh sach\n");
    printf("2. Them vao vi tri bat ki\n");
    printf("3. Dem so luong so chinh phuong\n");
    printf("4. Tinh trung binh cong cac so trong khoang x, y\n");
    printf("5. Tinh trung binh cong cac so le duong chia het cho 5\n");
    printf("6. Xem danh sach\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", &input);
    switch (input)
    {
      case 1:
      {
        int data;
        printf("Nhap so can them: ");
        scanf("%d", &data);
        addHead(data);
        printf("Them thanh cong!\n");
        checkInput = 1;
        break;
      }
      case 2:
      {
        int data, index;
        printf("Nhap so can them: ");
        scanf("%d", &data);
        printf("Nhap vi tri can them: ");
        scanf("%d", &index);
        addNodeByIndex(data, index);
        break;
      }
      case 3:
      {
        if(checkInput == 0){
          printf("Danh sach rong\n");
          break;
        }
        red();
        printf("So luong so chinh phuong: %d\n", countScp());
        reset();
        break;
      }
      case 4:
      {
        if(checkInput == 0){
          red();
          printf("Danh sach rong\n");
          reset();
          break;
        }
        int x, y;
        printf("Nhap x: ");
        scanf("%d", &x);
        printf("Nhap y: ");
        scanf("%d", &y);
        red();
        printf("Trung binh cong cac so trong khoang x, y: %lf\n", tbc(x, y));
        reset();
        break;
      }
      case 5:
      {
        if(checkInput == 0){
          red();
          printf("Danh sach rong\n");
          reset();
          break;
        }
        red();
        printf("Trung binh cong cac so le duong chia het cho 5: %lf\n", tbc_le_duong_5());
        reset();
        break;
      }
      case 6:
      {
        if(checkInput == 0){
          red();
          printf("Danh sach rong\n");
          reset();
          break;
        }
        red();
        viewList();
        reset();
        break;
      }
      case 7:
      {
        return 0;
      }
      default:{
        red();
        printf("Nhap sai, vui long nhap lai\n");
        reset();
        break;
      }
    }
  }
}
