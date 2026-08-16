# Write your MySQL query statement below
SELECT w1.id 
FROM Weather w1 
JOIN Weather w2 ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 
WHERE w1.temperature > w2.temperature; 
-- ensures w2 ek din peeche hai w1 se   aur w1 ka temp zyada hai w2 se