#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  char command[256];
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  int firstcount = count;
  printf("> Welcome!!\n");
  while(1){
	if(is_login==0) 
	{
		printf("> ");
		scanf("%s",command);
		if(!strcmp(command,"login"))
			is_login = login(userlist,count);
		else if(!strcmp(command,"join"))
			count = join(userlist,count);	
		else if(!strcmp(command,"list"))
			list(userlist,count);
		else if(!strcmp(command,"exit"))
			break;
		else printf("No such command!\n");
	}
	else
	{
		printf("# ");
		scanf("%s",command);
		if(!strcmp(command,"logout"))
				logout(&is_login);
		else printf("%s\n",command);
	}
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
