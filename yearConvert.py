# Converts a given amount of years, displays the equivalent in days, hours, minutes, and seconds.
valid_input = False
while(valid_input == False):
    years = input('Enter some number of years: ')
    try:
        years = int(years)
        valid_input = True
    except ValueError:
        print('Improper input, please enter an integer')

years_string = str("{:,}".format(years))
days = years * 365
days_string = str("{:,}".format(days))
hours = days * 24
hours_string = str("{:,}".format(hours))
minutes = hours * 60
minutes_string = str("{:,}".format(minutes))
seconds = minutes * 60
seconds_string = str("{:,}".format(seconds))

time_conversion = """\t\t{0} days
\t\t{1} hours
\t\t{2} minutes
\t\t{3} seconds """

print("   You entered {} years, which is equivalent to: ".format(years_string))
print(time_conversion.format(days_string,
                             hours_string, minutes_string, seconds_string))
