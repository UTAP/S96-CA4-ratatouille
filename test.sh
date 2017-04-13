Red='\033[1;31m'
NC='\033[0m' # No Color
Cyan='\033[1;36m'
Green='\033[1;32m'
Yellow='\033[1;33m'


cp testCases/customers.txt .
cp testCases/restaurants.txt .
mkdir -p answers

Ratatouille=./$1

for ((i=1; i<=7; i++))
do
	echo -e "${Cyan}test$i:${NC}"

	$Ratatouille <testCases/test$i >answers/ans$i

	totalLines=$(wc -l < testCases/ans$i)
	differentLines=$(diff -b -B -w -U 0 testCases/ans$i answers/ans$i | grep -v ^@ | wc -l)
	presentationError=$(diff -U 0 testCases/ans$i answers/ans$i | grep -v ^@ | wc -l)
	
	score=$(( (totalLines-differentLines)*100/totalLines ))

	echo -e "${Yellow}score: $score%${NC}"
	if ((presentationError!=0)) && (($(diff -b -B -w -y --suppress-common-lines testCases/ans$i answers/ans$i | wc -l)==0)) ; then
    	echo -e "${Red}Presentation Error : $presentationError${NC}"
	fi
	diff -b -B -w -y --suppress-common-lines testCases/ans$i answers/ans$i
	echo -e "${Green}---------------------------------------------------${NC}"
done


