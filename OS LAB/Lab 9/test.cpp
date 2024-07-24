# inc lude <unistd . h>
# inc lude < s t r i n g . h>
# inc lude < f c n t l . h>
# inc lude <iostream >
using namespace std ;
i n t main ( ) {
char s t r [ 2 5 6 ] = " h e l l o world " ;
i n t f i f o _ w r i t e ;
/ / o p en " pi p e _ o n e " wi t h WRITE o nl y mode
/ / and r e t u r n i t s f i l e d e s c r i p t o r
f i f o _ w r i t e = open ( " pipe_one " ,O_WRONLY) ;
/ / c h e c k i f o p en c a l l was s u c c e s s f u l
i f ( f i f o _ w r i t e < 0 ) {
cout <<" Error opening f i l e "
}
e l s e {
while ( strcmp ( s t r , " abort " ) ! = 0 ) {
cout <<" Enter t e x t : "<<endl ;
cin >> s t r ;
write ( f i f o _ w r i t e , s t r , s i z e o f ( s t r ) ) ;
cout <<" *
"<< s t r <<" *
"<<endl ;

}
c l o s e ( f i f o _ w r i t e ) ;
}
r e tu rn 0 ;
}