#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main()
{
	printf("Text file name: ");
	char name[128];
	scanf_s("%s", name, 128);



	////////////////////////헤더파일 작성

	//텍스트 파일 fopen
	FILE* file = fopen(name, "rb");
	if (file == NULL)
	{
		printf("fopen error \n");
	}

	//버퍼에 통으로 읽어오기
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	char* buffer = new char[size];
	rewind(file);
	int error = fread(buffer, size, 1, file);
	if (error == 0)
	{
		printf("fread error\n");
	}

	fclose(file);

	//생성할 파일 이름 뜯어오기
	char* ptr = buffer;
	char filename1[128];//헤더이름
	char filename2[128];//소스파일 이름
	int cnt = 0;
	while (1)
	{
		filename1[cnt] = *ptr;
		filename2[cnt] = *ptr;
		cnt++;
		ptr++;
		if (*ptr == 0x0d)
		{
			filename1[cnt] = '.';
			filename1[cnt + 1] = 'h';
			filename1[cnt + 2] = '\0';
			filename2[cnt] = '.';
			filename2[cnt + 1] = 'c';
			filename2[cnt + 2] = 'p';
			filename2[cnt + 3] = 'p';
			filename2[cnt + 4] = '\0';
			ptr += 5;
			break;
		}
	}
	//ptr현재 첫 함수 sendtype부분에 있음
	char sendtype[30];
	char func[30][256];
	char type[30][4];
	int cnt1 = 0;
	int cnt2 = 0;
	while (1)
	{
		sendtype[cnt1] = *ptr;
		ptr += 2;
		//한 줄씩 문자열 뜯어오고 header type도 뜯어오기
		while (1)
		{
			func[cnt1][cnt2] = *ptr;
			if (*ptr == ')')
			{
				ptr += 2;
				for (int i = 0; i < 4; i++)
				{
					type[cnt1][i] = *ptr;
					if (*(ptr + 1) == 0x0d)
					{
						type[cnt1][i + 1] = '\0';
						break;
					}
					ptr++;
				}
				func[cnt1][cnt2 + 1] = ';';
				func[cnt1][cnt2 + 2] = '\0';
				ptr += 3;

				cnt1++;
				cnt2 = 0;
				break;
			}


			cnt2++;
			ptr++;
		}

		if (*ptr == '}')
		{
			break;
		}

	}

	FILE* headerfile = fopen(filename1, "wb");
	fprintf(headerfile, "#ifndef __%s__\n#define __%s__\n\nstruct Player;\n\n", filename1, filename1);
	for (int i = 0; i < cnt1; i++)
	{
		fprintf(headerfile, "void %s\n", func[i]);
	}
	fprintf(headerfile, "\n\n#endif");


	fclose(headerfile);







	//소스파일생성
	FILE* srcfile = fopen(filename2, "wb");
	fprintf(srcfile, "#include \"%s\"\n", filename1);
	fprintf(srcfile, "#include \"SerialBuffer.h\"\n\n");
	for (int i = 0; i < cnt1; i++)
	{
		int packetsize = 0;
		int last = strlen(func[i]);
		func[i][last-1] = '\0';
		//인자 하나씩 뜯어서 parameter배열에 넣기...
		char parameter[30][32];
		int cnt3 = 0;
		int cnt4 = 0;
			for (int j = 0; j < 256; j++)
			{
				if (func[i][j] == ',')
				{

					int pos = j;
					while (func[i][pos] != ' ')
					{
						pos--;
					}
					
					pos++;
					int varcnt = pos-2;
					while (func[i][varcnt] != ' ')
					{
						varcnt--;
						if (func[i][varcnt] == '(')
						{
							break;
						}
					}
					varcnt++;
					switch (func[i][varcnt])
					{
					case 'c':
					{
						packetsize += 1;
						break;
					}
					case 's':
					{
						packetsize += 2;
						break;
					}
					case 'i':
					{
						packetsize += 4;
						break;
					}
					case 'l':
					{
						packetsize += 4;
						break;
					}
					case 'f':
					{
						packetsize += 4;
						break;
					}
					case 'd':
					{
						packetsize += 8;
						break;
					}
					default:
					{
						break;
					}
					}

					while (1)
					{
						parameter[cnt3][cnt4] = func[i][pos];
						pos++;
						cnt4++;
						if (func[i][pos] == ',')
						{
							parameter[cnt3][cnt4] = '\0';
							cnt3++;
							cnt4 = 0;
							break;
						}
					}


				}

				if (func[i][j] == ')')
				{
					int pos = j;
					while (func[i][pos] != ' ')
					{
						pos--;
					}
					pos++;
					int varcnt = pos - 2;
					while (func[i][varcnt] != ' ')
					{
						varcnt--;
						if (func[i][varcnt] == '(')
						{
							break;
						}
					}
					varcnt++;
					switch (func[i][varcnt])
					{
					case 'c':
					{
						packetsize += 1;
						break;
					}
					case 's':
					{
						packetsize += 2;
						break;
					}
					case 'i':
					{
						packetsize += 4;
						break;
					}
					case 'l':
					{
						packetsize += 4;
						break;
					}
					case 'f':
					{
						packetsize += 4;
						break;
					}
					case 'd':
					{
						packetsize += 8;
						break;
					}
					default:
					{
						break;
					}
					}
					while (1)
					{
						parameter[cnt3][cnt4] = func[i][pos];
						pos++;
						cnt4++;
						if (func[i][pos] == ')')
						{
							parameter[cnt3][cnt4] = '\0';
							cnt3++;
							cnt4 = 0;
							break;
						}
					}
					break;
				}
			}
			fprintf(srcfile,"void %s\n{\n", func[i]);
			fprintf(srcfile, "SBuffer buf;\nunsigned char code=0x89;\nunsigned char size=%d;\nunsigned char type=%s;\n",packetsize,type[i]);
			fprintf(srcfile, "buf<<code<<size<<type;\n");

			fprintf(srcfile, "buf");
			for (int c = 1; c < cnt3; c++)
			{
				fprintf(srcfile, "<<%s", parameter[c]);
			}
			fprintf(srcfile, ";\n\n");

			switch (sendtype[i])
			{
			case '0':
			{
				fprintf(srcfile, "SendBroadcast(nullptr,&buf);\n}\n\n");
				break;
			}
			case '1':
			{
				fprintf(srcfile, "SendUnicast(%s,&buf);\n}\n\n",parameter[0]);
				break;
			}
			case '2':
			{
				fprintf(srcfile, "SendBroadcast(%s,&buf);\n}\n\n", parameter[0]);
			}
			default:
			{
				break;
			}
			}

	}


	fclose(srcfile);


}