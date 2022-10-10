//
//  ClassesTableViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit

class ClassesTableViewCell: UITableViewCell {

    @IBOutlet weak var collectionView: UICollectionView!
    
    func setup() {
        collectionView.delegate = self
        collectionView.dataSource = self
        collectionView.register(UINib(nibName: "ActivesCollectionViewCell", bundle: nil), forCellWithReuseIdentifier: "ActivesCollectionViewCell")
    }
    
}

extension ClassesTableViewCell: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        1
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "ActivesCollectionViewCell", for: indexPath) as! ActivesCollectionViewCell
        cell.setupActives(symbolImage: "fiis", typeOfActives: "Fiis")
        return cell
    }
    
    
}
