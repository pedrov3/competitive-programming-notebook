for i in ../*.cpp ; do
    echo "\section{${i#../}}" 
    echo "\lstinputlisting{$i}" 
    echo ""
done 
