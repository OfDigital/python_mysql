#Connect on mysql by host,user,password and specially database
import mysql.connector as mysql

my_database = mysql.connect(
    host="localhost",
    user="root",
    password="",
    database="test"
)

# Making Cursor Object For Query Execution
my_cursor = my_database.cursor()
# Making Class for Cheacking functions
def selectMYSQL():
    sql = ("SELECT * FROM earthquakes")
    my_cursor.execute(sql)
    myresult = my_cursor.fetchall()
    for x in myresult:
      print(x)

  #selectMYSQL()


def describeDB():
    sql = ("DESCRIBE earthquakes")
    my_cursor.execute(sql)
    for x in my_cursor:
      print(x)

  #describeDB()

def check_database_isempty():
    try:
      area = input("Enter the Area : local or regional : ")
      sql = "Select * from earthquakes where area='" + area + "'"
      my_cursor.execute(sql)
      searchdata= my_cursor.fetchall()
      if searchdata:
        for s in searchdata:
          print(s)
      else:
        print("Please enter corect Area value")
    except:
      print("Error ...MY FRIEND")

  #check_database_isempty()

def check_corect_area():
      sql = "SELECT id from test.earthquakes where area not in ('local','global','regional','')"
      my_cursor.execute(sql)
      check_area = my_cursor.fetchall()
      if check_area:
        print("ERROR ERROR check_corect_area is done!\nPlease search incorrect id : ", check_area[:10])
      else:
        print("Evrything is greate, check_correct_area() is done")

  #check_corect_area()

def check_origin_msec():

      sql = "select id from test.earthquakes where origin_msec > 1000 or origin_msec < 0"
      my_cursor.execute(sql)
      check_msec = my_cursor.fetchall()
      if check_msec:
        print("Error Error check_origin_msec() is done!\nPlease Search Incorrect id : ", check_msec[0:10])
      else:
        print("Evrything is greate, check_origin_msec() is done")

  #check_origin_msec()