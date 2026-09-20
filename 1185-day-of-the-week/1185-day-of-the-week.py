import datetime

class Solution(object):
    def dayOfTheWeek(self, day, month, year):
        days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        return days[datetime.date(year, month, day).weekday()]