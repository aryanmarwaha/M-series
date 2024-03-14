from bs4 import BeautifulSoup as BS
import requests, csv

CSV_FILENAME = "results/results.csv"



def downloadImage(url, fileName):
	try:
		response = requests.get(url)
		with open(fileName, 'wb') as f1:
			f1.write(response.content)
	except:
		print("Error while downloading: "+ url, end="\n\n\n\n\n\n")



def writeToFile(fileName, data):
	with open(fileName, 'a') as f1:
		f1.write(data)



flag = True
def addToCSV(CSV_FILENAME, data):
	global flag
	with open(CSV_FILENAME, 'a') as f1:
		fieldnames = list(data.keys())
		writer = csv.DictWriter(f1, fieldnames=fieldnames)
		if flag:
			writer.writeheader()
			flag=False
		writer.writerow(data)



if __name__ == '__main__':
	
	response = requests.get('https://results.eci.gov.in/AcResultByeJan2024/candidateswise-S203.htm')
	soup = BS(response.text, 'html.parser')
	data = soup.body.main.div.find_all('div', class_='col-md-4 col-12')
	for candidateDiv in data:

		candidate = candidateDiv.div
		img = candidate.figure.img.get('src')

		downloadImage(img, "./results/images/" + img.split('/')[-1])
		candidateStatus = candidate.div.find('div', class_='status')
		candidateID = candidate.div.find('div', class_='nme-prty')
		d = {}
		d['candidate-name'] = candidateID.h5.text
		d['party-name'] = candidateID.h6.text
		d['status'] = candidateStatus.text.split('\n')[1]
		d['votes'] = candidateStatus.text.split('\n')[2]
		d['image-url'] = img
		addToCSV(CSV_FILENAME, d)