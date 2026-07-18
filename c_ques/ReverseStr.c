#include<stdio.h>

void reverse_string(char *str) {
    int left = 0, right = 0;
    
    while (str[right] != '\0') right++;
    right--;

    while(left < right) {

	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;
	
	right--;
	left++;
    }
}

int main() {
    
    char str[100];
    printf("Enter String: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') i++;
    str[i] = '\0';

    printf("Before : %s\n", str);
    reverse_string(str);
    printf("After : %s\n", str);
    
    return 0;
}
