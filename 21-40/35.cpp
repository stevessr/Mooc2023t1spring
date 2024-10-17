    #include <iostream>
    using std::cout,std::endl,std::cin,std::string;
    auto output(auto input){

    if (input == 1){
        return 1;
    }else if (input == 2){
        return 2;
    }else{
    int ab = 1 , af = 2,temp;input-=2;
    for (int i=0;i<input;i++){
    temp = 2*af+ab;
    ab = af%32767 ;
    af = temp%32767;
    }
    return temp%32767;
    }
    }
    int main(){
        int T,input;
        cin>>T;
        while(T--){
            cin>>input;
            cout<<output(input)<<endl;
        }
        return 0;
    }
