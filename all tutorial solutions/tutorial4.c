1. A   0 00000000 00000000000000000000000
	= 0 float

   B   1 00000000 00000000000000000000000
   	= - 0 float

   C   0 01111111 10000000000000000000000
   =   +  (1+0.5)*2^(127-127)
   =  +1.5 

   D   0 01111110 00000000000000000000000
   =   + (1+0)*2^(126-127) 
   =   + 2^(-1)
   =   + 0.5

   E   0 01111110 11111111111111111111111
   =   + (1+0.99999999999)2^(126-127)
   =   +1
   
   F   0 10000000 01100000000000000000000
   =   + (1+0.25+0.125)*(2^128-127)
   =   + 2.75

   G   0 10010100 10000000000000000000000
   =   + (1+0.5)*2^(128+4+16-127(21))
   =   + 3145728

   H   0 01101110 10100000101000001010000
   =   + (1+0.5+0.125+2^-9+2^-11+2^-17+2^-19) *2^(2+4+8+32+64-127)
   =   + (1+0.62745094299)*(2^-17)
   =   + 0.00001241646


2  A  2.5
   2.5 = (1+frac)*2^(n-127)
   2.5 = 1.25 * 2
   so 2.5 = (1+0.25)*2^1
   therefore 
   frac = 0.25 (2^-2)
   exp = 128
   sign = +
   2.5 = 0 10000000 0100000000000000000000

   B 0.375
   0.375 = (1+frac)*2^(n-127)
   0.375 = (1+0.5)*2^(-2)
   so 
   frac  = 0.5
   exp = 126
   sign = +
   0.375 = 0 01111110 10000000000000000000

   C 27
   27 = (1+ frac)*2^(n-127)
   27 = (1+ 0.6875)*2^(4)
   so
   frac = 0.6875
   exp = 131
   sign = +
   27 = 0 10000011 10110000000000000000

   D 100
   100 = (1+frac)*2^(n-127)
   100 = (1+0.5625)*2^(6)
   so
   frac = 0.5625
   exp = 133
   sign = +
   100 = 0 10000101 100100000000000000


3. A. int new adress 0x7ffff004  			bytes in an int			4
   B. short int new adress 0x7ffff002 	 	bytes in a short int	2
   C. char new address 0x7ffff001     		bytes in a char 		1
   D. double new address 0x7ffff008         bytes in double 		8
   E. struct xyz new address 0x7ffff0C      bytes in the struct 	12 
   F  struct abc new address 0x7ffff0C      bytes in the struct 	12 

4. int myStrCmp(char *a,char *b){
		while(*a != '\0' && *b != '\0'){
			if(*a<*b) return -1;
			if(*a>*b) return 1;
			else{
				a++;
				b++;
			}
		}
		if(*b == '\0' && *a! = '\0') return 1;
		if(*b!= '\0' && *a=='\0') return -1;
		return 0;

	}

5. A Implement the makeNode() and freeNode operations for Node1 style nodes.
typedef struct _node1 Node1;
struct _node1 {
   Node1 *next;
   char *str;
};
Node1 *makeNode1(char *smthn){
	Node1 *new = malloc(sizeof(struct _node1));
	new->next = next;
	new->str = malloc(sizeof(strlen(smthn))+1);
	strcpy(new->str,smthn);
	or new->str = strdup(smthn);
	return new;
}

void freeNode1(Node1 *head){
	Node *tmp;
	Node *curr = head;
	while(curr != NULL){
		tmp = curr;
		curr = curr->next;
		free(tmp->str);
		free(tmp);
	}
}
   B Implement the makeNode() and freeNode operations for Node2 style nodes.
typedef struct _node2 Node2;
struct _node2 {
   Node2 *next;
   char str[100];
};
Node2 *makeNode2(char *smthn, Node2 *next){
	Node2 *new = malloc(sizeof(struct _node1));
	new->next = next;
	for(int i = 0;i<100;i++)new->str[i] = 0;
	for(int i = 0;smthn[i]!='\0';i++) new->str[i] = smthn[i]; 
	or new->str = strdup(smthn);
	return new;
}

void freeNode2(Node2 *head){
	Node *tmp;
	Node *curr = head;
	while(curr != NULL){
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
typedef struct _node3 Node3;
struct _node3 {
   Node3 *next;
   char str[1];
};
Node3 *makeNode3(char *smthn, Node2 *next){
	Node3 *new = malloc(sizeof(struct _node3) + strlen(smthn));
	new->next = next;
	for(int i = 0;i<100;i++)new->str[i] = 0;
	for(int i = 0;smthn[i]!='\0';i++) new->str[i] = smthn[i]; 
	return new;
}

void freeNode3(Node3 *head){
	Node *tmp;
	Node *curr = head;
	while(curr != NULL){
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

  D. Node1 very good uses just enough space for the string and the next node, need to free string on deletion
  	 Node2 is not so good uses fixed space so it could lead to issue of buffer overflow or overallocating
  	 Node3 is similair to node1 where it allocates just enough space for the string and the next node but doesnt allocate memory to the string

7. var.u(  �*�oy retne            �	        ަ�A\T4~@��Ⱥ.        ~ReT��4 �n��.  �      �A�'3ZF���[u�.  �      Iu6�fio,@���.        �kҔ܏���2�E��.  >      ���}�#�@G
d��.  �      �@^���@��E��.        T&8� 2�@���.  �      =����. ۤS�.        �>��*��@!zO6�.        �d�!���@��$��.  =      ��WX�t') �B���.  %      Ox�-�L�@bF��.  C      Q�+"�)�@Ih��.  