class Solution {
public:
    string s="";

    int ac=0, bc=0, cc=0; 

    string longestDiverseString(int a, int b, int c) {

        if(a<=0 && b<=0 && c<=0)
        {    
            return s;
        }
               
        if((a>0 && a>=b && a>=c && ac!=2) || (a>0 && (bc==2 || cc==2)))
        {
            s+='a';
            ac++;
            bc=0, cc=0;
        
            longestDiverseString(a-1, b, c);
        }
        else if((b>0 && b>=c && b>=a && bc!=2) || (b>0 && (ac==2 || cc==2)))
        {
            s+='b';
            bc++;
            ac=0, cc=0;
                
            longestDiverseString(a, b-1, c);
        }   
        else if((c>0 && c>=a && c>=b && cc!=2) || (c>0 && (ac==2 || bc==2)))
        {
            s+='c';
            cc++;
            ac=0, bc=0;

            longestDiverseString(a, b, c-1);
        }
        
        return s;

    }
};