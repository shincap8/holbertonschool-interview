#!/usr/bin/node
const myArgs = process.argv.slice(2);
const reqURL = 'https://swapi-api.hbtn.io/api/films/' + myArgs[0];
const request = require('request');

if (Number.isInteger(parseInt(myArgs[0]))) {
  request(reqURL,
    async (error, response, body) => {
      if (error) console.error('error:', error);
      const characters = JSON.parse(body).characters;
      for (let i = 0; i < characters.length; i++) {
        const name = await Name(characters[i]);
        console.log(name);
      }
    }
  );
}

function Name (Namelink) {
  const name = new Promise(
    (resolve, reject) => {
      request(Namelink, (error, response, body) => {
        if (error) console.error('error:', error);
        resolve(JSON.parse(body).name);
      });
    });
  return name;
}
