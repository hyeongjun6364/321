import re

#연산,피연산자구분 리스트
result=[']1','+','4]2','%','!3!%&^&5','=']

for i in range(0,len(result)-1):
    if(i%2==0):
        data=result[i]#슬라이싱
        number=re.sub(r'[^0-9]','',data)#숫자추출 정규식
        result[i]=number
        result[i]=int(result[i])#int 형변환
      
#결과 확인
print(result)



#for i in range(0,len(result)-1):
    #if(result[i]!='+'): 
#for i in range(0,len(result)-1):#0~리스트길이만큼 반복
     #split_text=result.split()#공백기준으로 리스트 나누기
     #print(split_text)
#stringstrip=result[i].strip()
    #print(stringstrip[i])