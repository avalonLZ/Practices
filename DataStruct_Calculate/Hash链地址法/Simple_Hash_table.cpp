/*************************************************************************
	> File Name: Simple_Hash_table.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 01:15:44 AM PDT
 ************************************************************************/

#include"Simple_Hash_table.h"

HashList::HashList()
{
    unsigned char i;
    for(i = 0; i < 25; ++i)
    {
        list[i] = NULL;
    }
}

void HashList::DataInput(const char *data)
{
    unsigned char key = 0;
    unsigned char len = 0;

    len = strlen(data)+1;
    
    if(len >= 3)
    {
        key = ((unsigned char)data[0]+(unsigned char)data[1])%23;
        //cout << "key = " << key << "len = " << len << endl;
        printf("key = %d\n", key);
        if(list[key] == NULL)
        {
            list[key] = (Hnode *)malloc(sizeof(Hnode));
            list[key]->behind = NULL;
            list[key]->data = (char *)malloc(len);
            memcpy(list[key]->data, data, len);
        }
        else
        {
            while(1)
            {
                list[key] = list[key]->behind;
                
                if(list[key] == NULL)
                {
                    break;
                }
            }            
            list[key] = (Hnode *)malloc(sizeof(Hnode));
            list[key]->behind = NULL;
            list[key]->data = (char *)malloc(len);
            memcpy(list[key]->data, data, len);
        }
    }
}

string HashList::DataOutput(const char *temp)
{
    unsigned char key = 0;
    key = ((unsigned char)temp[0]+(unsigned char)temp[1])%23;
    string tstr = temp;
    string dstr = list[key]->data;
    while(1)
    {
        if(list[key] == NULL)
        {
            dstr = "No Data!";
            return dstr;
        }
        else if(tstr == dstr)
        {
            return dstr;
        }
        else
        {
            list[key] = list[key]->behind;
            
            if(list[key] == NULL)   
            {
                dstr = "No Data!";
                return dstr;
            }
            else
            {
                dstr = list[key]->data;
                continue;
            }
        }
    }
}
