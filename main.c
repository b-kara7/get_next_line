#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


//int main() //ilk satırı yazdırma leeksiz
//{
//	char *line;

//	int fd= open("denem.txt", O_CREAT | O_RDONLY, 0777);

//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	close(fd);
//}



//int main() // tüm dosyayı okuyorum
//{
//	char *line;

//	int fd = open("deneme.txt", O_CREAT | O_RDWR, 0777);

//	while((line = get_next_line(fd)))
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
	
//}



//int main() // tüm dosyayı okuyorum
//{
//	char *line;

//	int fd = open("deneme.txt", O_CREAT | O_RDWR, 0777);
//	write(fd,"betul\nesra\nkara", 15);

//	while((line = get_next_line(fd)))
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
	
//}





//void recursive(int fd) // tersten yazdırma 
//{
//	char *line;
//	line = get_next_line(fd);
//	if(line)
//	{
//		recursive(fd);
//		printf("%s", line);
//	}
//}

//int main()
//{
//	int fd =open("deneme", O_CREAT | O_RDWR, 0777);
//	recursive(fd);
//	close (fd);
//}






//int main() // terminalden yazdırma
//{
//	char *line;
	
//	while((line = get_next_line(0)))
//	{
//		printf("%s", line);
//		free(line);
//	}
//} terminalden girdi alıdğımızda ctrl d ile kapatıyoruz çünkü programı güvenli şekilde ve leeksiz bitiriyor.
// 



//int main() // terminalden yazdırma
//{
//	char *line;
//	int fd = open("deneme", O_CREAT | O_RDWR | O_TRUNC, 0777);

	
//	while((line = get_next_line(0)))
//	{
		
//		write(fd, line, ft_strlen(line));
//		free(line);
//	}
//	close(fd);
//}
//ctrl c dediğimde leekli çalışıyor direk kodu kesiyor, ctrl d dediğimde leek durumu yok controllü programı kapatıyor.




