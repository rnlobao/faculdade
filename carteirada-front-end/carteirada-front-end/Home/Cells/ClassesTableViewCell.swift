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
        collectionView.register(ActivesCollectionViewCell.nib(), forCellWithReuseIdentifier: ActivesCollectionViewCell.identifier)
    }
    
}

extension ClassesTableViewCell: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        3
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "ActivesCollectionViewCell", for: indexPath) as! ActivesCollectionViewCell
        if indexPath.row == 0 {
            cell.setupActives(symbolImage: "chart.bar.fill", typeOfActives: "Ações")
        } else if indexPath.row == 1 {
            cell.setupActives(symbolImage: "building.2", typeOfActives: "Fii's")
        } else {
            cell.setupActives(symbolImage: "dollarsign.square.fill", typeOfActives: "Criptoativos")
        }
        return cell
    }
    
    
}
