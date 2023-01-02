#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int result=0;

const int ALPHABET_SIZE = 2;
string toBinary(unsigned long int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
      for(int i=r.length();i<8;i++){
        r+="0";
    }
    return r;
}
string toBinary2(unsigned long int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
      for(int i=r.length();i<32;i++){
        r+="0";
    }
    return r;
}/*
string ConvertTo8Bits(int x){
	vector<int> ret(32);
	int i=31;
	while(x) {
	    if (x&1)
	    	ret[i]=1;
	    else
	    	ret[i]=0;
	    i--;
	    x>>=1;
	}
  	return ret;
}*/
//-------------------------------------

//Convert IP address to binary representation
//--------------------------------------
string ConvertToBinary(string s){
	unsigned long int n=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		n += pow(10,s.length()-1-i) * ((int) s[i] - 48);

	}
	return toBinary(n);
}
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int  data;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}
void insert(struct TrieNode *root, string key,int len,int rulenum)
{
    struct TrieNode *pCrawl = root;
    int i;
    for ( i = 0; i <len; i++)
    {
        int index = key[i] - '0';
        //cout<<key[i]<<endl;
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->data=rulenum;
}
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
int i;
    for ( i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
       // cout<<key[i]<<endl;





        if (!pCrawl->children[index]){
           // cout<<pCrawl->data<<endl;

            return pCrawl->data;
        }


        pCrawl = pCrawl->children[index];//往第幾個child走
    }
  //  cout<<pCrawl->data<<endl;

    return (pCrawl->data);
}
int main() {
    vector<string> ip1s;
    vector<string> ip2s;
     vector<int> port1s;
    vector<int> port2s;
    vector<int> port3s;
    vector<int> port4s;
     vector<string> ptls;
      int ans;
      struct TrieNode *root1 = getNode();
      struct TrieNode *root2 = getNode();
      int lensize;

    std::ifstream ifs("acl1_10k.txt", std::ios::in);
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    } else {
       string ip1;
    string ip2;
    int port1;
    int port2;
    int port3;
   int port4;
     string ptl;
     //string ptl_fix;
     string no1;
     string no2;
    lensize=0;
        string s;



        while (ifs >> ip1 >> ip2>> port1 >>no1>> port2>>port3 >>no2>> port4>> ptl ) {
        ip1s.push_back(ip1);
        ip2s.push_back(ip2);
        port1s.push_back(port1);
        port2s.push_back(port2);
        port3s.push_back(port3);
        port4s.push_back(port4);

        ptls.push_back(ptl);


      //  cout<<ip1s[i][1]<<endl;
           /* int len=name.length();
            cout<<len<<endl;

            if(name[len-3]=='/'){
                ans=(name[len-2]-'0')*10+(name[len-1]-'0');
            }
            else{
                ans=(name[len-1]-'0');
            }

            cout<<ans<<endl;*/
            lensize++;
        }
        ifs.close();
    }
    ifs.close();

    while(1){
        int checksum;
       unsigned long int inp1;
        string inp1b;
       unsigned long int inp2;
        string inp2b;
        int inp3;
        int inp4;
        int inp5;

    cin>>inp1>>inp2>>inp3>>inp4>>inp5;
    inp1b=toBinary2(inp1) ;
    string inp1b_rev (inp1b.rbegin(), inp1b.rend());
    inp2b=toBinary2(inp2) ;
    string inp2b_rev (inp2b.rbegin(), inp2b.rend());
    if(inp1==0){
        inp1b_rev+="0";
    }
    if(inp2==0){
        inp2b_rev+="0";
    }
   // cout<<inp2b_rev<<endl;

/*
vector<int> v=ConvertToBinary(inp1b);
            //    cout<<"v is ";
                for (int j=0;j<=7;j++){
                    int v1=v[j];
                    cout<<v[j]<<"v1 is ="<<v1;
                    cout<<endl;
                  //  ins+=to_string(v1);
                }*/
    for(int i=0;i<lensize;i++){
    checksum=0;
    int ip1len=0;
    ip1len=ip1s[i].length();
    if((ip1s[i][ip1len-2]=='/')&&(ip1s[i][ip1len-1]=='0')){
        checksum+=1;
    }
    else{
            int s=1;

        string temp;
        string ins;
        if(ip1s[i][ip1len-3]=='/'){
                ans=(ip1s[i][ip1len-2]-'0')*10+(ip1s[i][ip1len-1]-'0');
            }
            else{
                ans=(ip1s[i][ip1len-1]-'0');
            }


        while(ip1s[i][s]!='/')
		{

			if(ip1s[i][s]=='.')
			{
             //   cout<<"ip"<<ip1s[i][s]<<endl;
               // cout<<"temp="<<temp<<endl;
				string v1=ConvertToBinary(temp);
                string v1_rev (v1.rbegin(), v1.rend());
           //     cout<<"v1="<<v1_rev<<endl;
                ins+=v1_rev;

				temp = "";
			}

			else temp += ip1s[i][s];

			s++;

		}
		string v1=ConvertToBinary(temp);
        string v1_rev (v1.rbegin(), v1.rend());

		temp="";
		ins+=v1_rev;
        if(ins.compare(0,ans,inp1b_rev,0,ans)==0){
        checksum+=1;
        }

    }

int ip2len=0;
    ip2len=ip2s[i].length();
    if((ip2s[i][ip2len-2]=='/')&&(ip2s[i][ip2len-1]=='0')){
        checksum+=1;
    }
    else{
            int s=0;

        string temp;
        string ins;
        if(ip2s[i][ip2len-3]=='/'){
                ans=(ip2s[i][ip2len-2]-'0')*10+(ip2s[i][ip2len-1]-'0');
            }
            else{
                ans=(ip2s[i][ip2len-1]-'0');
            }
           // cout<<"ans "<<i<<"="<<ans<<endl;

        while(ip2s[i][s]!='/')
		{

			if(ip2s[i][s]=='.')
			{
              //  cout<<"ip"<<ip2s[i][s]<<endl;
              //  cout<<"temp="<<temp<<endl;
				string v1=ConvertToBinary(temp);
                string v1_rev (v1.rbegin(), v1.rend());
             //   cout<<"v1="<<v1_rev<<endl;
                ins+=v1_rev;

				temp = "";
			}

			else temp += ip2s[i][s];

			s++;

		}
		string v1=ConvertToBinary(temp);
        string v1_rev (v1.rbegin(), v1.rend());

		temp="";
		ins+=v1_rev;
		//cout<<"ins "<<i<<" ="<<ins<<endl;
        if(ins.compare(0,ans,inp2b_rev,0,ans)==0){
        checksum+=1;
        }

    }

    if((inp3>=port1s[i])&&(inp3<=port2s[i])){
            checksum+=1;
        }
     if((inp4>=port3s[i])&&(inp4<=port4s[i])){
            checksum+=1;
        }
     if(ptls[i][8]=='0'){
        checksum+=1;
     }
     else{
        int dig=ptls[i][3]-'0';
        int dig2=ptls[i][2]-'0';
        if(ptls[i][3]=='a'){
            dig=10;
        }
        if(ptls[i][3]=='b'){
            dig=11;
        }
        if(ptls[i][3]=='c'){
            dig=12;
        }
        if(ptls[i][3]=='d'){
            dig=13;
        }
        if(ptls[i][3]=='e'){
            dig=14;
        }
        if(ptls[i][3]=='f'){
            dig=15;
        }
        int check=((dig2)*16)+dig;
        //cout<<"check"<<check<<endl;
        if (check==inp5){
            checksum+=1;

        }
     }

    if(checksum==5){

        cout<<"ANS="<<i+1<<endl;
        result=1;
        break;
    }

    }


if(result==0){
    cout<<"NP"<<endl;
}

    }

 return 0;
}
