=begin

  Class Name: GradeBook
  
=end

BEGIN{

	class GradeBook
		
		@@courseName = ""

		def initialize(name = "")
			setCourseName(name)
		end

		def setCourseName(name)
			@@courseName = name
		end

		def getCourseName
			@@courseName 
		end


		def displayMessage

			puts "Welcome to the Grade Book #{getCourseName}!\n"
		end

	end

	def main

		myGradeBook = GradeBook.new # create a GradeBook object named myGradeBook
		myGradeBook.displayMessage	# call object's displayMessage function

		puts "Initial course name is #{myGradeBook.getCourseName}"
		
		puts "\nPlease enter the course name: "
		nameOfCourse = gets.chomp

		myGradeBook.setCourseName(nameOfCourse)

		myGradeBook.displayMessage

	end


	main

}

END {

	#puts "Terminate program!"

}

