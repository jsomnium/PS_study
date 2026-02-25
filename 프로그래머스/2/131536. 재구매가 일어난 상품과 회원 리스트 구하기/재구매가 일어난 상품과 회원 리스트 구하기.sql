SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID        -- 유저와 상품을 한 쌍으로 묶음
HAVING COUNT(*) >= 2                -- 그 쌍의 개수가 2개 이상인 것만 필터링
ORDER BY USER_ID ASC, PRODUCT_ID DESC;