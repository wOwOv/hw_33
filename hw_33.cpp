#define _CRT_SECURE_NO_WARNINGS

#include <iostream>



//대문자로 변환하는 함수
void to_upper(char* p);


int main()
{
	
	printf("Text file name: ");
	char name[128];
	scanf_s("%s", name, 128);
	


	//////////////////////헤더파일 작성

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
	char definename[2][128];//Proxy Stub 헤더 define 이름
	char headername[2][128];//헤더이름 Proxy Stub
	char cppname[2][128];//소스파일 이름 Proxy Stub
	char procname[128];//proc 이름
	int cnt = 0;
	while (*ptr != 0x0d)
	{
//#define , 헤더이름, 소스파일 이름 만들기

		definename[0][cnt] = *ptr;
		definename[1][cnt] = *ptr;
		headername[0][cnt] = *ptr;
		headername[1][cnt] = *ptr;
		cppname[0][cnt] = *ptr;
		cppname[1][cnt] = *ptr;
		procname[cnt] = *ptr;
		cnt++;
		ptr++;
	}

//#define 
	strcpy(&definename[0][cnt], "PROXY");
	strcpy(&definename[1][cnt], "STUB");

	//헤더파일
	strcpy(&headername[0][cnt], "proxy.h");
	strcpy(&headername[1][cnt], "stub.h");

	//소스파일
	strcpy(&cppname[0][cnt], "proxy.cpp");
	strcpy(&cppname[1][cnt], "stub.cpp");

	//procname
	procname[cnt] = '\0';


	ptr += 5;


	//ptr현재 첫 함수 이름시작부분에 있음
	char func[30][2][256];
	char type[30][4];
	int cnt1 = 0;
	int cnt2 = 0;

	while (1)
	{
		//함수명(까지 뜯어오기
			while (1)
			{
				func[cnt1][0][cnt2] = *ptr;
				if (*ptr == '(')
				{
					func[cnt1][0][cnt2 + 1] = '\0';
					cnt2 = 0;
					ptr++;
					break;
				}
				cnt2++;
				ptr++;
			}

		//(다음부터 뜯고 헤더타입도 뜯어오기
			while (1)
			{
				
				func[cnt1][1][cnt2] = *ptr;
				if (*ptr == ';')
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
					func[cnt1][1][cnt2 + 1] = '\0';
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



	//----proxy.h  파일 생성
		FILE * headerfile = fopen(headername[0], "wb");
	fprintf(headerfile, "#ifndef __%s__\n#define __%s__\n\nstruct Player;\n\n", definename[0], definename[0]);
	for (int i = 0; i < cnt1; i++)
	{
		//인자에 unicast
			fprintf(headerfile, "void U%sPlayer* player,%s\n", func[i][0], func[i][1]);

		//broadcast
			fprintf(headerfile, "void RB%s%s\n", func[i][0], func[i][1]);

		//인자제외 broadcast
			fprintf(headerfile, "void B%sPlayer* player,%s\n", func[i][0], func[i][1]);
	}
	fprintf(headerfile, "\n\n#endif");


	fclose(headerfile);







	//----proxy.cpp 파일 생성
		FILE * srcfile = fopen(cppname[0], "wb");
	fprintf(srcfile, "#include \"%s\"\n", headername[0]);
	fprintf(srcfile, "#include \"SerialBuffer.h\"\n");
	fprintf(srcfile, "#include \"SendCast.h\"\n\n\n");
	for (int i = 0; i < cnt1; i++)
	{
		int packetsize = 0;
		int last = strlen(func[i][1]);
		func[i][1][last - 1] = '\0';
		//인자 하나씩 뜯어서 parameter배열에 넣기...
			char parameter[30][32];
		int cnt3 = 0;
		int cnt4 = 0;
		for (int j = 0; j < 256; j++)
		{
			if (func[i][1][j] == ',')
			{
				int pos = j;
				while (func[i][1][pos] != ' ')
				{
					pos--;
				}

				pos++;
				int varcnt = pos - 2;
				while (func[i][1][varcnt] != ' ')
				{
					varcnt--;
					if (func[i][1][varcnt] == '(')
					{
						break;
					}
				}
				varcnt++;
				switch (func[i][1][varcnt])
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
					parameter[cnt3][cnt4] = func[i][1][pos];
					pos++;
					cnt4++;
					if (func[i][1][pos] == ',')
					{
						parameter[cnt3][cnt4] = '\0';
						cnt3++;
						cnt4 = 0;
						break;
					}
				}


			}

			if (func[i][1][j] == ')')
			{
				int pos = j;
				while (func[i][1][pos] != ' ')
				{
					pos--;
				}
				pos++;
				int varcnt = pos - 2;
				while (func[i][1][varcnt] != ' ')
				{
					varcnt--;
					if (func[i][1][varcnt] == '(')
					{
						break;
					}
				}
				varcnt++;
				switch (func[i][1][varcnt])
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
					parameter[cnt3][cnt4] = func[i][1][pos];
					pos++;
					cnt4++;
					if (func[i][1][pos] == ')')
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
		fprintf(srcfile, "void U%sPlayer* player,%s\n{\n", func[i][0], func[i][1]);
		fprintf(srcfile, "SBuffer buf;\nunsigned char code=0x89;\nunsigned char size=%d;\nunsigned char type=%s;\n", packetsize, type[i]);
		fprintf(srcfile, "buf<<code<<size<<type;\n");

		fprintf(srcfile, "buf");
		for (int c = 0; c < cnt3; c++)
		{
			fprintf(srcfile, "<<%s", parameter[c]);
		}
		fprintf(srcfile, ";\n\n");
		fprintf(srcfile, "SendUnicast(player,&buf);\n}\n\n");





		fprintf(srcfile, "void RB%s%s\n{\n", func[i][0], func[i][1]);
		fprintf(srcfile, "SBuffer buf;\nunsigned char code=0x89;\nunsigned char size=%d;\nunsigned char type=%s;\n", packetsize, type[i]);
		fprintf(srcfile, "buf<<code<<size<<type;\n");

		fprintf(srcfile, "buf");
		for (int c = 0; c < cnt3; c++)
		{
			fprintf(srcfile, "<<%s", parameter[c]);
		}
		fprintf(srcfile, ";\n\n");
		fprintf(srcfile, "SendBroadcast(nullptr,&buf);\n}\n\n");




		fprintf(srcfile, "void B%sPlayer* player,%s\n{\n", func[i][0], func[i][1]);
		fprintf(srcfile, "SBuffer buf;\nunsigned char code=0x89;\nunsigned char size=%d;\nunsigned char type=%s;\n", packetsize, type[i]);
		fprintf(srcfile, "buf<<code<<size<<type;\n");

		fprintf(srcfile, "buf");
		for (int c = 0; c < cnt3; c++)
		{
			fprintf(srcfile, "<<%s", parameter[c]);
		}
		fprintf(srcfile, ";\n\n");
		fprintf(srcfile, "SendBroadcast(player,&buf);\n}\n\n");

	}


	fclose(srcfile);

	//----stub.h  파일 생성
	
	//define할 것들 문자열 만들어두기
	char def[30][256];
	for (int i = 0; i < cnt1; i++)
	{
		strcpy(def[i], "DEF");
		char temp[256];
		strcpy(temp, func[i][0]);
		to_upper(temp);
		strcat(def[i], temp);
		int lastw = strlen(def[i]);
		def[i][lastw - 1] = '\0';
	}
	//stub헤더 코드 쓰기
	FILE* stubheader = fopen(headername[1], "wb");
	fprintf(stubheader, "#ifndef __%s__\n#define __%s__\n\nstruct Player;\nstruct SBuffer;\n\n", definename[1], definename[1]);
	for (int i = 0; i < cnt1; i++)
	{
		//type[i]에서 숫자 1빼서 넣어주기
		int num = atoi(type[i]);
		num--;
		char stubtype[8];
		_itoa_s(num, stubtype, sizeof(stubtype), 10);
		fprintf(stubheader, "#define %s %s\n", def[i], stubtype);
	}
	fprintf(stubheader,"\n\n");
	for (int i = 0; i < cnt1; i++)
	{
		fprintf(stubheader, "void Req%sPlayer* player,SBuffer* buf);\n", func[i][0]);
	}

	//처리할 코드
	fprintf(stubheader, "void %sProc(Player* player,SBuffer* buf);\n", procname);

	fprintf(headerfile, "\n\n#endif");

	fclose(stubheader);

	//----stub.cpp  파일 생성
	FILE* stubcpp = fopen(cppname[1], "wb");
	fprintf(srcfile, "#include \"%s\"\n", headername[1]);
	fprintf(srcfile, "#include \"Struct.h\"\n#include \"SerialBuffer.h\"\n\n");
	
	//처리할 코드
	fprintf(stubheader, "void %sProc(Player* player,SBuffer* buf)\n{\n", procname);
	fprintf(stubheader, "unsigned char code;\nunsigned char size;\nunsigned char type;\n");
	fprintf(stubheader, "*buf>>code>>size>>type;\n");
	fprintf(stubheader, "switch(type)\n{\n");
	for (int i = 0; i < cnt1; i++)
	{
		fprintf(stubheader, "case %s:\n{\n", def[i]);
		fprintf(stubheader, "Req%splayer,buf);\n", func[i][0]);
		fprintf(stubheader, "break;\n");
		fprintf(stubheader, "}\n");
	}
	fprintf(stubheader, "default:\n{\nbreak;\n}\n");
	fprintf(stubheader, "}\n}\n\n");
	fclose(stubcpp);
}




void to_upper(char* p)
{
	int count = 0;
	int diff = 'a' - 'A';
	while (p[count] != 0)
	{
		if (p[count] >= 97 && p[count] <= 122)
		{
			p[count] -= diff;
		}
		count++;
	}

}
