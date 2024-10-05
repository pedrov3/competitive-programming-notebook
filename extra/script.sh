echo "\section{Geral}" 
for i in ../*.cpp ; do
    echo "\subsection{${i#../}}" 
    echo "\lstinputlisting{$i}" 
    echo ""
done



exit 0

echo "\section{Problemas}" 
for i in ../problemas/*.cpp ; do
    echo "\subsection{${i#../problemas/}}" 
    echo "\lstinputlisting{$i}" 
    echo ""
done 
