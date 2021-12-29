import pymysql
from mysql_connector import Cheacking

#database connection
connection = pymysql.connect(host="localhost",user="root",passwd="",database="test" )
cursor = connection.cursor()
# some other statements  with the help of curs
def check_origin_msec():
    sql = "select id from test.earthquakes where origin_msec > 1000 or origin_msec < 0"
    cursor.execute(sql)
    check_msec = cursor.fetchall()
    if check_msec:
        print("Error Error check_origin_msec() is done!\nPlease Search Incorrect id : ", check_msec[0:10])
    else:
        print("Evrything is greate, check_origin_msec() is done")


check_origin_msec()
connection.close()
