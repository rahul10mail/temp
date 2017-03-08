#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getstring(char *str);
char *bit_stuff(char *in, char *out);

int main()
{
	char *bit_str = malloc(0);
	char *stuffed_bit = malloc(0);
	
	bit_str = getstring(bit_str);
	stuffed_bit = bit_stuff(bit_str, stuffed_bit);
	
	printf("%s\n", (stuffed_bit));
	
	return 0;
}

char *bit_stuff(char *in, char *out)
{
	const char *search_bits = "111111";
	char *s = strstr(in, search_bits), *new, *t = in;
	
	if ( s == NULL )
	{
		return in;
	}

	new = realloc(out, strlen(in) + 1);
		
	if ( new == NULL )
	{
		fprintf(stderr, "realloc failed in bitstuff\n");
		
		exit(EXIT_FAILURE);
	}
	
	out = new;

	while ( s != NULL )
	{
		new = realloc(out, strlen(out) + 1);
		
		if ( new == NULL )
		{
			fprintf(stderr, "realloc failed in bitstuff\n");
			
			exit(EXIT_FAILURE);
		}
		
		out = new;
		
		strncat(out, t, s - t + 5);

		out[strlen(out)] = '0';
		
		s += 5;
		t = s;
		s = strstr(s, search_bits);
	}
   
	strcat(out, t);	

	out[strlen(out)] = '\0';
	
	return out;
}

char *getstring(char *str)
{
	int ch, n = 0;
	char *new;
	
	while ( (ch = fgetc(stdin)) != '\n' )
	{
		++n;
		
		new = realloc(str, n);
		
		if ( new == NULL )
		{
			fprintf(stderr, "realloc failed in getstring\n");
			
			exit(EXIT_FAILURE);
		}
		
		str = new;
		
		str[n - 1] = ch;
	}
	
	++n;
	
	new = realloc(str, n);
		
	if ( new == NULL )
	{
		fprintf(stderr, "realloc failed in getstring\n");
		
		exit(EXIT_FAILURE);
	}
	
	str = new;
	str[n - 1] = '\0';	

	return str;
}
