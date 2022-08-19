// Love babbar String question
int isCyclicRotation(string &p, string &q) 
{
    if(p.length() != q.length())
           return false;

       p = p+p;
       
       if(p.find(q) == -1)
            return false;
       
       return true;
}
