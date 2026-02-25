SELECT 
    PT_NAME, 
    PT_NO, 
    GEND_CD, 
    AGE, 
    IFNULL(TLNO, 'NONE') AS TLNO -- NULL이면 'NONE'으로 출력
FROM PATIENT
WHERE AGE <= 12                -- 12세 이하 (13 미만도 맞지만 보통 <= 12로 표현)
  AND GEND_CD = 'W'            -- 여자환자 조건 추가!
ORDER BY AGE DESC, PT_NAME ASC; -- 나이 내림차순, 이름 오름차순