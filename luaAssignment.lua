function calcArea(type)
	if type == 1 then
		print("Enter length:")
		local length = io.read("*n")
		print("Enter width:")
		local width = io.read("*n")
		return length*width
	elseif type == 2 then
		print("Enter base length:")
		local base = io.read("*n")
		print("Enter height:")
		local height = io.read("*n")
		return .5*base*height
	elseif type == 3 then
		print("Enter radius:")
		local radius = io.read("*n")
		return 3.14 * radius * radius --math.pi works... :-)
	else
		print("Incorrect type entered.")
	end
end

print("Enter which shape you want to calculate area for:")
print("1: Rectangle")
print("2: Triangle")
print("3: Circle")
print("Type: ")
local type = io.read("*n")
print("Area: "..calcArea(type))