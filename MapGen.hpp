void MapGen(int& dimension, char (&mine)[25][25])
{
	int s;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			s = 0;
			if (mine[i][j] != '*')
			{
                if (mine[i - 1][j - 1] == '*')
                    s++;

                if (mine[i - 1][j] == '*')
                    s++;

                if (mine[i][j - 1] == '*')
                    s++;       
        
                if (mine[i - 1][j + 1] == '*')
                    s++;           
            
                if (mine[i + 1][j] == '*')           
                    s++;   
                
                if (mine[i + 1][j - 1] == '*')         
                    s++;                  
                    
                if (mine[i + 1][j + 1] == '*')        
                    s++;  

                if (mine[i][j + 1] == '*')                        
                    s++;
                            
                mine[i][j] =char (s+48);
			}
		}
	}
		
}