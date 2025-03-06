fetch('students.json')
  .then(response => response.json())
  .then(data => {
      // Insert data into the HTML table
  })
  .catch(error => console.error('Error loading data:', error));
